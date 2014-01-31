/***************************************************************
 * Name:      LotoClicApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Yann Morère (yann@morere.eu)
 * Created:   2013-10-13
 * Copyright: Yann Morère (http://www.morere.eu)
 * License:
 **************************************************************/

#include "LotoClicApp.h"

//(*AppHeaders
#include "LotoClicMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LotoClicApp);

bool LotoClicApp::OnInit()
{
     // we're using wxConfig's "create-on-demand" feature: it will create the
  // config object when it's used for the first time. It has a number of
  // advantages compared with explicitly creating our wxConfig:
  //  1) we don't pay for it if we don't use it
  //  2) there is no danger to create it twice

  // application and vendor name are used by wxConfig to construct the name
  // of the config file/registry key and must be set before the first call
  // to Get() if you want to override the default values (the application
  // name is the name of the executable and the vendor name is the same)
  SetVendorName(_T("wxWidgets"));
  SetAppName(_T("LotoClick")); // not needed, it's the default value

  wxConfigBase *pConfig = wxConfigBase::Get();

  // uncomment this to force writing back of the defaults for all values
  // if they're not present in the config - this can give the user an idea
  // of all possible settings for this program
  pConfig->SetRecordDefaults();

  // or you could also write something like this:
  //  wxFileConfig *pConfig = new wxFileConfig("conftest");
  //  wxConfigBase::Set(pConfig);
  // where you can also specify the file names explicitly if you wish.
  // Of course, calling Set() is optional and you only must do it if
  // you want to later retrieve this pointer with Get().

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LotoClicFrame* Frame = new LotoClicFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    //Number=0;
    return wxsOK;

}

int LotoClicApp::OnExit()
{
  // clean up: Set() returns the active config object as Get() does, but unlike
  // Get() it doesn't try to create one if there is none (definitely not what
  // we want here!)
  delete wxConfigBase::Set((wxConfigBase *) NULL);

  return 0;
}


/*
int LotoClicApp::FilterEvent(wxEvent& event)
{

    if ((event.GetEventType() == wxEVT_KEY_DOWN) && (((wxKeyEvent&)event).GetKeyCode() == WXK_NUMPAD5))
    {
       Number = 5;
       wxString msg = _("Number="+Number);//wxbuildinfo(long_f);
        wxMessageBox(msg, _("About ..."));
       //frame->OnHelpF1( (wxKeyEvent&)event );

        return true;
    }

    return -1;
}
*/
