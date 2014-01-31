#include "numberPopup.h"
#include <wx/display.h>
//(*InternalHeaders(numberPopup)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(numberPopup)
const long numberPopup::ID_BUTTON1 = wxNewId();
const long numberPopup::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(numberPopup,wxFrame)
	//(*EventTable(numberPopup)
	//*)
END_EVENT_TABLE()

numberPopup::numberPopup(wxWindow* parent,int ratio, wxColour colourGreen, wxWindowID)
{
    //wxSizerFlags flagsExpand(1);
    //flagsExpand.Expand().Border(wxALL, 2);
	//(*Initialize(numberPopup)
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE|wxFRAME_NO_TASKBAR|wxNO_BORDER, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&numberPopup::OnButton1Click);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&numberPopup::OnTimer1Trigger);
	//*)
	//find the screen size
	wxSize displaySize = wxGetDisplaySize();
    this->SetSize(wxDefaultCoord,wxDefaultCoord,wxRound((double(displaySize.GetWidth()))*(((double)ratio)/100)), wxRound((double(displaySize.GetHeight()))*(((double)ratio)/100)),wxSIZE_FORCE);
    Button1->SetBackgroundColour(colourGreen);
    this->SetBackgroundColour(colourGreen);

}

void numberPopup::setText(wxString txt, int FontSize, int timer)
{
	//(* Set the static text
	//*)
    wxFont font = Button1->GetFont();
    font.SetPointSize(FontSize);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    //Button1->SetForegroundColour(*wxBLUE);
    //StaticText1->SetCentre();
    Button1->SetFont(font);
	Button1->SetLabel(txt);
	Timer1.Start(timer); //5s default
}


numberPopup::~numberPopup()
{
	//(*Destroy(numberPopup)
	//*)
}


void numberPopup::OnButton1Click(wxCommandEvent& event)
{
    this->Hide();
}

void numberPopup::OnTimer1Trigger(wxTimerEvent& event)
{
    this->Hide();
}
