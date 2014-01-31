/***************************************************************
 * Name:      LotoClicMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Yann Morère (yann@morere.eu)
 * Created:   2013-10-13
 * Copyright: Yann Morère (http://www.morere.eu)
 * License:
 **************************************************************/

/***************************************************************
 * Important
 * RPi en startx
 * Stockage de la configuration de lotoclic (si fichier absent -> Plantage)
 * pi@raspberrypi ~ $ more .LotoClick
 * [UserPrefs]
 * VocalSynthesis=1
 * Timer=3
 * ButtonFontSize=36
 * LabelFontSize=36
 * PopupLabelFontSize=250
 * PopupSizeRatio=60
 * ButtonRedColorSelection=red
 * ButtonGreenColorSelection=rgb(0, 255, 7)
 *
 * Dans le cas de gnome stockage dans
 * fichier binaire non lisible
 *
 * pour voir ce qui est chargé : strace -o loading.txt -e open ./bin/Debug/LotoClick
**************************************************************/


#include "LotoClicMain.h"
#include "numberPopup.h"
//extern "C" {
//#include "picotts.h"
 //}

#include <wx/msgdlg.h>
#include <wx/wx.h>
#include <wx/display.h>
#include <wx/aboutdlg.h>
#include <wx/icon.h>

//to include icon : convert as an xpm file and add the const keyword in the xpm file :
// static const char *logo_lotoclic_200px...
// and rename logo_lotoclic_200px to logo_lotoclic_200px_xpm, wxWidget needs that.
#include "logo_lotoclic_200px.xpm"


//(*InternalHeaders(LotoClicFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(LotoClicFrame)
const long LotoClicFrame::ID_STATICLINE1 = wxNewId();
const long LotoClicFrame::ID_STATICTEXT1 = wxNewId();
const long LotoClicFrame::ID_STATICTEXT2 = wxNewId();
const long LotoClicFrame::ID_idMenuReset = wxNewId();
const long LotoClicFrame::idMenuPrefs = wxNewId();
const long LotoClicFrame::idMenuQuit = wxNewId();
const long LotoClicFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(LotoClicFrame,wxFrame)
    //(*EventTable(LotoClicFrame)
    //*)
    EVT_TIMER(wxID_ANY, LotoClicFrame::OnTimer)
END_EVENT_TABLE()

LotoClicFrame::LotoClicFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LotoClicFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("LotoClick"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(800,600));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    GridSizer1 = new wxGridSizer(11, 10, 0, 0);
    BoxSizer1->Add(GridSizer1, 9, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticLine1->SetMinSize(wxSize(-1,-1));
    BoxSizer1->Add(StaticLine1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 11, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu1, ID_idMenuReset, _("Reset\tAlt-R"), _("Reset Application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem3 = new wxMenuItem(Menu1, idMenuPrefs, _("Preferences\tAlt-P"), _("Préférences Utilisateur"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&LotoClic"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_idMenuReset,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotoClicFrame::OnMenuIResetSelected);
    Connect(idMenuPrefs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotoClicFrame::OnMenuPrefsSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotoClicFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LotoClicFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&LotoClicFrame::OnClose);
    //*)



    wxSizerFlags flagsExpand(1);
    flagsExpand.Expand().Border(wxALL, 2);

    wxString  txt = wxT("");
    // mConfig before mPopup, need ratio info to construct mPopup
    mConfig = new UserConfig(0);

    colorGreen = wxColour(mConfig->GetButtonGreenColorSelection());
    colorRed = wxColour(mConfig->GetButtonRedColorSelection());
    mPopup = new numberPopup(0, mConfig->GetPopupSizeRatio(), colorGreen);

    bool layoutRawColumn = mConfig->GetButtonLayoutValue();
    //New frame
    if (layoutRawColumn)
    {
    for(wxInt16 i=0;i<10;i++)
    {
        wxButton* button = 0;
        for(wxInt16 j=0;j<10;j++)
            {
            wxInt16 txtint = j*10+i;
            if ((txtint ==0) || (txtint >90))
            {
            txt = wxT("");
            button = new wxButton(this,wxID_ANY,txt);
            button->Enable(false);
            }
            else
            {
            txt = wxString::Format(wxT("%i"),txtint);
            button = new wxButton(this,wxID_ANY,txt);
            }
            //store all the button in a list to retreive them after
            listAllButton.push_back(button);
            wxFont font = button->GetFont();
            font.SetPointSize(mConfig->GetButtonFontSizeValue());
            font.SetWeight(wxFONTWEIGHT_BOLD);
            button->SetFont(font);
            GridSizer1->Add(button,flagsExpand);
            button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LotoClicFrame::buttonClick), NULL, this );
            button->GetId();
            }
    }
    }
    else
    {
    for(wxInt16 i=1;i<91;i++)
    {
    txt = wxString::Format(wxT("%i"),i);
    wxButton* button = new wxButton(this,wxID_ANY,txt);
    //store all the button in a list to retreive them after
    listAllButton.push_back(button);
    wxFont font = button->GetFont();
    font.SetPointSize(mConfig->GetButtonFontSizeValue());
    font.SetWeight(wxFONTWEIGHT_BOLD);
    button->SetFont(font);
    GridSizer1->Add(button,flagsExpand);
    button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LotoClicFrame::buttonClick), NULL, this );
    button->GetId();
    }
    }
 /*
    txt = wxT("Reset");
    wxButton* button = new wxButton(this,wxID_ANY,txt);
    //store all the button in a list to retreive them after
    listAllButton.push_back(button);
    wxFont font = button->GetFont();
    font.SetPointSize(18);
    font.SetWeight(wxFONTWEIGHT_BOLD);

    button->SetFont(font);
    GridSizer1->Add(button,flagsExpand);
    button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LotoClicFrame::buttonClick), NULL, this );
    button->GetId();
*/
    //wxTopLevelWindow::Maximize(true);
    //window size to display size :
    wxSize displaySize = wxGetDisplaySize();
    //this->SetSize(wxDefaultCoord,wxDefaultCoord,displaySize.GetWidth()/2, displaySize.GetHeight()/2,wxSIZE_FORCE);
    this->SetSize(wxDefaultCoord,wxDefaultCoord,displaySize.GetWidth(),displaySize.GetHeight(),wxSIZE_FORCE);
    //this->SetSize(0,0,1024,768,wxSIZE_FORCE);

/*
    //load sound file:
    m_soundFile=wxT("jingles/pacman.wav");
    if ( !m_sound )
    {
        m_sound = new wxSound;
    }

    m_sound->Create(m_soundFile);
*/
    //To get keys globally
    //http://wiki.wxwidgets.org/Catching_key_events_globally#Regular_Polling
    timer = new wxTimer(this, wxID_ANY);
    timer->Start(125);
    Numbers[0]=-1;
    Numbers[1]=-1;

    }

void LotoClicFrame::doHandleButtonClick(wxButton* myButton)
{
    wxColour myButtonColor = myButton->GetBackgroundColour();
    wxColour myButtonDefaultColor = myButton->GetClassDefaultAttributes().colBg;
    wxString number;
/*
    if (myButton->GetLabel() == wxT("Reset"))
    {
        int answer = wxMessageBox(wxT("Do you want to reset all buttons?"), wxT("Reset"), wxYES_NO, NULL);
        if (answer == wxYES)
        {
        StaticText1->SetLabel(wxT("")); //clear button list
        StaticText2->SetLabel(wxT("")); //clear button list
        // make the default color for button
        for(unsigned ind=0;ind<listSelectedButton.size(); ind++)
        {
            (listSelectedButton.at(ind))->SetBackgroundColour(myButtonDefaultColor);
        }
        //clear the list
        listSelectedButton.clear();
        }
    }
    else
    {*/
        if (myButtonColor == colorGreen)
        {
        listSelectedButton.pop_back();
        myButton->SetBackgroundColour(myButtonDefaultColor);
        if (listSelectedButton.size()>0)
            {
            (listSelectedButton.at(listSelectedButton.size()-1))->SetBackgroundColour(colorGreen);
            }
        //else
        //{
         //   (listSelectedButton.at(listSelectedButton.size()))->SetBackgroundColour(colorGreen);
        //}
        }
    if (myButtonColor == myButtonDefaultColor)
    {
        listSelectedButton.push_back(myButton);
        (listSelectedButton.back())->SetBackgroundColour(colorGreen);
        if (listSelectedButton.size()>1)
        {
                (listSelectedButton.at(listSelectedButton.size()-2))->SetBackgroundColour(colorRed);
        }

    number = (listSelectedButton.back())->GetLabel();
    wxFont font = StaticText1->GetFont();
    font.SetPointSize(mConfig->GetButtonFontSizeValue());
    font.SetWeight(wxFONTWEIGHT_BOLD);

        //wxMessageBox(number);
    mPopup->Centre(wxBOTH); //center on the display
    mPopup->setText(number, mConfig->GetPopupLabelFontSizeValue(), (mConfig->GetTimerValue())*1000);
    //mPopup->SetFocus();
    //mPopup->Raise();
   	mPopup->Show();

    if (mConfig->GetVocalSynthesisValue())
        {
        wxString cmd = wxT("pico2wave -l fr-FR -w /tmp/test.wav \"")+ myButton->GetLabel() + wxT("\"");
        //wxString cmd = wxT("pico2wave -l fr-FR -w /tmp/test.wav \"")+ myButton->GetLabel() + wxT("\" && aplay /tmp/test.wav");
        wxString cmd2 = wxT("aplay /tmp/test.wav");
        //wxShell(cmd);
        //wxArrayString output, errors;
        wxExecute(cmd, wxEXEC_NODISABLE|wxEXEC_SYNC);
        wxExecute(cmd2, wxEXEC_NODISABLE|wxEXEC_SYNC);
        }
    //int code = wxExecute(cmd, output, errors);
    //wxLogStatus(_T("Shell command '%s' terminated with exit code %d."),cmd.c_str(), code);
//    m_cmdLast = cmd;


    //m_sound->Play(wxSOUND_ASYNC);
   	//wxSleep(3);
   	//mPopup->Hide();
   	//SetTopWindow(mPopup);
   	//wait some time

    /*}*/

    //wxFont font = StaticText2->GetFont();
    wxString listNumber, listNumber2;
    //wxFont font = StaticText1->GetFont();
    //Affichage de la liste de numéro
    if (listSelectedButton.size()>1)
    {
    listNumber = _("");
    unsigned ind=0;
    if (listSelectedButton.size()>10)
        ind = listSelectedButton.size() - 10;
    for(unsigned ind2=ind;ind2<listSelectedButton.size()-1; ind2++)
        {
        listNumber += ((listSelectedButton.at(ind2))->GetLabel() + wxT(","));
        }
    //wxFont font = StaticText1->GetFont();
    font.SetPointSize(mConfig->GetLabelFontSizeValue());
    font.SetWeight(wxFONTWEIGHT_BOLD);

    StaticText1->SetFont(font);
    StaticText1->SetForegroundColour(colorRed);
    StaticText1->SetLabel(listNumber);

    listNumber2 = _("");
    listNumber2 = (listSelectedButton.at(listSelectedButton.size()-1))->GetLabel();

    }
    else
    {
        if (listSelectedButton.size()==0)
        {
            listNumber2 = _("");
         }
        else
        {
        listNumber = _("");
        font.SetPointSize(mConfig->GetLabelFontSizeValue());
        font.SetWeight(wxFONTWEIGHT_BOLD);

        StaticText1->SetFont(font);
        StaticText1->SetForegroundColour(colorRed);
        StaticText1->SetLabel(listNumber);
        listNumber2 = _("");
        //wxString listNumber2 = _("");

        listNumber2 = (listSelectedButton.at(listSelectedButton.size()-1))->GetLabel();
        }
    }
    font.SetPointSize(mConfig->GetLabelFontSizeValue());
    font.SetWeight(wxFONTWEIGHT_BOLD);
    StaticText2->SetFont(font);
    StaticText2->SetForegroundColour(colorGreen);
    StaticText2->SetLabel(listNumber2);
    }
}

void LotoClicFrame::buttonClick(wxCommandEvent& event)
{
    wxButton *myButton = (wxButton*)event.GetEventObject();
    doHandleButtonClick(myButton);
}


LotoClicFrame::~LotoClicFrame()
{
    //(*Destroy(LotoClicFrame)
    //*)

    wxConfigBase *pConfig = wxConfigBase::Get();
    if ( pConfig == NULL )
    return;
    // save the control's values to the config
    pConfig->Write(_T("/UserPrefs/ButtonLayout"), mConfig->GetButtonLayoutValue());
    pConfig->Write(_T("/UserPrefs/VocalSynthesis"), mConfig->GetVocalSynthesisValue());
    pConfig->Write(_T("/UserPrefs/Timer"), mConfig->GetTimerValue());
    pConfig->Write(_T("/UserPrefs/ButtonFontSize"), mConfig->GetButtonFontSizeValue());
    pConfig->Write(_T("/UserPrefs/LabelFontSize"), mConfig->GetLabelFontSizeValue());
    pConfig->Write(_T("/UserPrefs/PopupSizeRatio"), mConfig->GetPopupSizeRatio());
    pConfig->Write(_T("/UserPrefs/PopupLabelFontSize"), mConfig->GetPopupLabelFontSizeValue());
    pConfig->Write(_T("/UserPrefs/ButtonRedColorSelection"), mConfig->GetButtonRedColorSelection());
    pConfig->Write(_T("/UserPrefs/ButtonGreenColorSelection"), mConfig->GetButtonGreenColorSelection());


    delete mConfig;
    delete mPopup;
    delete m_sound;
}

void LotoClicFrame::OnQuit(wxCommandEvent& event)
{
    /*int answer = wxMessageBox(wxT("Do you really want to quit?"), wxT("Quit"), wxYES_NO, NULL);
        if (answer == wxYES)
        {
        Close();
        }*/
        this->OnClose((wxCloseEvent&)(event));

}

void LotoClicFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = _("LotoClic - Y. Morère - 2013\n Code::Blocks - wxWidgets\n");//wxbuildinfo(long_f);
    //wxMessageBox(msg, _("About ..."));
    wxIcon icon(wxICON(logo_lotoclic_200px));
    wxAboutDialogInfo info;
    info.SetName(wxT("LotoClic"));
    info.SetVersion(wxT("0.1"));
    info.SetDescription(wxT("Display live Loto/Bingo results on a big screen ;-)."));
    info.SetLicence(wxT("Licence GPL V3 : http://www.gnu.org/licenses/quick-guide-gplv3.fr.html\n\n Les principes de base de la GPL\n\n Personne ne doit être limité par les logiciels qu'il utilise.\n Il y a quatre libertés que tout utilisateur doit posséder :\n - la liberté d'utiliser le logiciel pour n'importe quel usage,\n - la liberté de modifier le programme pour répondre à ses besoins,\n - la liberté de redistribuer des copies à ses amis et voisins,\n - la liberté de partager avec d'autres les modifications qu'il a faites."));
    info.SetCopyright(wxT("(C) 2013-2014 <yann@morere.eu>"));
    //info.SetVersion(MY_APP_VERSION_STRING);
    //info.SetCopyright(wxT("(C) 1992-2010"));
    info.SetWebSite(wxT("http://www.morere.eu"));
    info.AddDeveloper(wxT("Yann"));
    info.AddDocWriter(wxT("Yann"));
    info.SetIcon(icon);

    wxAboutBox(info);
}

void LotoClicFrame::OnTimer(wxTimerEvent& event)
{
    wxString msg;
    int res = -1;
    int num = -1;
	timer->Stop();
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD0)))
    {
    //msg = wxT("0");
    //wxLogMessage(msg);
    num = 0;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD1)))
    {
    //msg = wxT("1");
    //wxLogMessage(msg);
    num = 1;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD2)))
    {
    //msg = wxT("2");
    //wxLogMessage(msg);
    num = 2;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD3)))
    {
    //msg = wxT("3");
    //wxLogMessage(msg);
    num = 3;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD4)))
    {
    //msg = wxT("4");
    //wxLogMessage(msg);
    num = 4;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD5)))
    {
    //msg = wxT("5");
    //wxLogMessage(msg);
    num = 5;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD6)))
    {
    //msg = wxT("6");
    //wxLogMessage(msg);
    num = 6;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD7)))
    {
    //msg = wxT("7");
    //wxLogMessage(msg);
    num = 7;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD8)))
    {
    //msg = wxT("8");
    //wxLogMessage(msg);
    num = 8;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD9)))
    {
    //msg = wxT("9");
    //wxLogMessage(msg);
    num = 9;
	}
	if (wxGetKeyState(wxKeyCode(WXK_NUMPAD_ADD)))
    {
    //msg = wxT("ENTER");
    //wxLogMessage(msg);
    //select button where the label is NumberDEc*10+NumberUnit
    if (Numbers[0]!=-1)
    {
        //msg = wxString::Format(wxT("%i"),NumberCount);
        //wxLogMessage(msg);
        if ((Numbers[0] != -1)&&(Numbers[1] == -1))
            {
            res = Numbers[0];
            }
        else
            {
            if ((Numbers[0] != -1)&&(Numbers[1] != -1))
                {
                res = Numbers[0]*10+Numbers[1];
                }
            else
                {
                //problem
                wxLogMessage(wxT("Problem : no more than 2 digits"));
                res=-1;
                }
            }
            msg = wxString::Format(wxT("%i"),res);
            //wxLogMessage(msg);
            //research the button in a list
            wxWindow* wintmp = FindWindowByLabel(msg, NULL);
            if (wintmp != NULL)
            {
            wxButton *buttonSelected = wxDynamicCast(wintmp, wxButton);
            //do the stuff for the button
            doHandleButtonClick(buttonSelected);
            //wxString test = buttonSelected->GetLabel();
            //wxCommandEvent ev(wxEVT_COMMAND_BUTTON_CLICKED, buttonSelected->GetId());
            //buttonSelected->GetEventHandler()->ProcessEvent(ev);
            //buttonSelected->ProcessEvent(ev);
            }


    }
    //initialize Numbers
    //NumberCount=-1;
    Numbers[0]=-1;
    Numbers[1]=-1;
	}

    if (num!=-1)
    {
        //store
        if (Numbers[0]==-1)
        {
            Numbers[0] = num;
        }
        else
        {
            Numbers[1]=num;
        }
    }
    num=-1;
	timer->Start();

}

void LotoClicFrame::OnMenuPrefsSelected(wxCommandEvent& event)
{
    mConfig->Show();
}

void LotoClicFrame::OnMenuIResetSelected(wxCommandEvent& event)
{
    wxMenu *myMenu = (wxMenu*)event.GetEventObject();
    wxWindow *myWindow = (wxWindow *) myMenu->GetParent();
    //wxColour myButtonColor = myWindow->GetBackgroundColour();
    wxColour myButtonDefaultColor = myWindow->GetClassDefaultAttributes().colBg;
 int answer = wxMessageBox(wxT("Do you want to delete the actual serie?"), wxT("Reset"), wxYES_NO, NULL);
        if (answer == wxYES)
        {
        StaticText1->SetLabel(wxT("")); //clear button list
        StaticText2->SetLabel(wxT("")); //clear button list
        // make the default color for button
        for(unsigned ind=0;ind<listSelectedButton.size(); ind++)
        {
            (listSelectedButton.at(ind))->SetBackgroundColour(myButtonDefaultColor);
        }
        //clear the list
        listSelectedButton.clear();
        }
}

void LotoClicFrame::OnClose(wxCloseEvent& event)
{
     int answer = wxMessageBox(wxT("Do you really want to quit?"), wxT("Quit"), wxYES_NO, NULL);
        if (answer == wxYES)
        {
        Destroy();
        }
}
