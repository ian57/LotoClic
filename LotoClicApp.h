/***************************************************************
 * Name:      LotoClicApp.h
 * Purpose:   Defines Application Class
 * Author:    Yann Morère (yann@morere.eu)
 * Created:   2013-10-13
 * Copyright: Yann Morère (http://www.morere.eu)
 * License:
 **************************************************************/

#ifndef LOTOCLICAPP_H
#define LOTOCLICAPP_H

#include <wx/config.h>
#include <wx/app.h>

class LotoClicApp : public wxApp
{
    public:
        //int Number;
        virtual bool OnInit();
        virtual int OnExit();
        //int FilterEvent(wxEvent& event);

};

#endif // LOTOCLICAPP_H
