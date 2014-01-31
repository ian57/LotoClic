/***************************************************************
 * Name:      LotoClicMain.h
 * Purpose:   Defines Application Frame
 * Author:    Yann Morère (yann@morere.eu)
 * Created:   2013-10-13
 * Copyright: Yann Morère (http://www.morere.eu)
 * License:
 **************************************************************/

#ifndef LOTOCLICMAIN_H
#define LOTOCLICMAIN_H

#include "numberPopup.h"
#include "UserConfig.h"
#include <wx/wx.h>
#include <iostream>
#include <vector>
//libwx is not compiled to support SDL. Alsa is not yet supported by wx. Need to install aoss to wrap oss to alsa
//use is : aoss LotoClic to get sound
#include <wx/sound.h>

//(*Headers(LotoClicFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class LotoClicFrame: public wxFrame
{
    public:

        LotoClicFrame(wxWindow* parent,wxWindowID id = -1);
        void buttonClick(wxCommandEvent& event);
        void doHandleButtonClick(wxButton* myButton);
        void OnTimer(wxTimerEvent& event);
        virtual ~LotoClicFrame();

    private:

        //(*Handlers(LotoClicFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuPrefsSelected(wxCommandEvent& event);
        void OnMenuIResetSelected(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(LotoClicFrame)
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_idMenuReset;
        static const long idMenuPrefs;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(LotoClicFrame)
        wxStaticText* StaticText1;
        wxMenuItem* MenuItem3;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText2;
        wxMenuItem* MenuItem4;
        //*)
        std::vector<wxButton*> listSelectedButton;
        std::vector<wxButton*> listAllButton;
        numberPopup* mPopup;
        UserConfig* mConfig;
        wxSound* m_sound;
        wxColour colorGreen;
        wxColour colorRed;
        //int mTimer;
        wxString m_soundFile;
        wxTimer* timer;
        int Numbers[2];
        DECLARE_EVENT_TABLE()
};

#endif // LOTOCLICMAIN_H
