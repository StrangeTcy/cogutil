/*
 * opencog/embodiment/Control/Procedure/ComboShellServer.cc
 *
 * Copyright (C) 2007-2008 TO_COMPLETE
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "comboreduct/combo/vertex.h"
#include <iostream>
#include <sstream>

#include "ComboShellServer.h"
#include <boost/lexical_cast.hpp>
#include "ComboInterpreter.h"
#include "ComboProcedureRepository.h"
#include "StringMessage.h"
#include "PetComboVocabulary.h"

using namespace Procedure;
using namespace PetCombo;
using namespace boost;
using namespace std;
using namespace MessagingSystem;

BaseServer* ComboShellServer::createInstance()
{
    return new ComboShellServer;
}

ComboShellServer::ComboShellServer()
{
}

void ComboShellServer::init(const Control::SystemParameters &params)
{
    setNetworkElement(new NetworkElement(params,
                                         params.get("COMBO_SHELL_ID"),
                                         params.get("COMBO_SHELL_IP"),
                                         lexical_cast<int>(params.get("COMBO_SHELL_PORT"))));
    _waiting = false;
}

bool ComboShellServer::processNextMessage(MessagingSystem::Message *msg)
{
    if (msg->getTo() != getID())
        return false;
    string res = msg->getPlainTextRepresentation();

    if (res == "action_failure")
        cout << "execution failed!" << endl;
    else {
        if (res != "action_success")
            cout << "result: " << res << endl;
        cout << "execution succeeded!" << endl;
    }
    _waiting = false;
    return false;
}

bool ComboShellServer::customLoopRun()
{
    if (_waiting) {
        return EmbodimentCogServer::customLoopRun();
    }

    combo_tree tr;
    if (!cin.good()) {
        cout << endl;
        exit(0);
    }

start:
    cout << "> ";
    if (cin.peek() == ' ' ||
            cin.peek() == '\n' ||
            cin.peek() == '\t')
        cin.get();
    while (cin.peek() == ' ' ||
            cin.peek() == '\n' ||
            cin.peek() == '\t') {
        if (cin.peek() == '\n')
            cout << "> ";
        cin.get();
    }
    if (cin.peek() == '#') { //a comment line
        char tmp[1024];
        cin.getline(tmp, 1024);
        goto start;
    }
    cin >> tr;
    if (!cin.good()) {
        cout << endl;
        exit(0);
    }

    try {
        stringstream ss;
        ss << tr;
        StringMessage msg(getParameters().get("COMBO_SHELL_ID"),
                          "1", //to the OPC - this is a hack...
                          ss.str());
        cout << "sending schema " << ss.str() << "..." << endl;
        sendMessage(msg);
        cout << "schema sent to OPC, waiting for result ..." << endl;
        _waiting = true;
    } catch (...) {
        cout << "execution failed (threw exception)" << endl;
    }

    return true;
}
