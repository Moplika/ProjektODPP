import QtQuick 2.4

NewClientForm {
    btn_addClient.onClicked: {
        uiHandler.addNewClient( text_clientId.text,
                               text_clientName.text,
                               text_timeStage1.text,
                               text_timeStage2.text,
                               text_timeStage3.text,
                               text_timeStage4.text);
    }
}
