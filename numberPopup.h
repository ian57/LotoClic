#ifndef NUMBERPOPUP_H
#define NUMBERPOPUP_H

#include <wx/wx.h>
//(*Headers(numberPopup)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
//*)

class numberPopup: public wxFrame
{
	public:

		//numberPopup(wxWindow* parent,wxWindowID id=wxID_ANY);
		//numberPopup(wxWindow* parent,int ratio, wxWindowID id=wxID_ANY);
		numberPopup(wxWindow* parent,int ratio, wxColour colourGreen, wxWindowID id=wxID_ANY);
		void setText(wxString txt, int FontSize, int timer);
		virtual ~numberPopup();

		//(*Declarations(numberPopup)
		wxButton* Button1;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(numberPopup)
		static const long ID_BUTTON1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(numberPopup)
		void OnButton1Click(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		//*)
        wxTimer mTimer;

		DECLARE_EVENT_TABLE()
};

#endif
