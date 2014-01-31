#include "UserConfig.h"

//(*InternalHeaders(UserConfig)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/colordlg.h>
#include <wx/msgdlg.h>
#include <wx/brush.h>

//(*IdInit(UserConfig)
const long UserConfig::ID_STATICTEXT9 = wxNewId();
const long UserConfig::ID_CHECKBOX2 = wxNewId();
const long UserConfig::ID_STATICTEXT1 = wxNewId();
const long UserConfig::ID_CHECKBOX1 = wxNewId();
const long UserConfig::ID_STATICTEXT2 = wxNewId();
const long UserConfig::ID_SPINCTRL1 = wxNewId();
const long UserConfig::ID_STATICTEXT4 = wxNewId();
const long UserConfig::ID_SPINCTRL3 = wxNewId();
const long UserConfig::ID_STATICTEXT5 = wxNewId();
const long UserConfig::ID_SPINCTRL4 = wxNewId();
const long UserConfig::ID_STATICTEXT8 = wxNewId();
const long UserConfig::ID_SPINCTRL5 = wxNewId();
const long UserConfig::ID_STATICTEXT3 = wxNewId();
const long UserConfig::ID_SPINCTRL2 = wxNewId();
const long UserConfig::ID_STATICTEXT6 = wxNewId();
const long UserConfig::ID_BUTTON3 = wxNewId();
const long UserConfig::ID_STATICTEXT7 = wxNewId();
const long UserConfig::ID_BUTTON4 = wxNewId();
const long UserConfig::ID_BUTTON1 = wxNewId();
const long UserConfig::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(UserConfig,wxFrame)
	//(*EventTable(UserConfig)
	//*)
END_EVENT_TABLE()

UserConfig::UserConfig(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(UserConfig)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;

	Create(parent, wxID_ANY, _("Préférences Utilisateur"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextButtonLayout = new wxStaticText(this, ID_STATICTEXT9, _("Button Layout"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer11->Add(StaticTextButtonLayout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBoxButtonLayout = new wxCheckBox(this, ID_CHECKBOX2, _("On (Column) / Off (Row)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBoxButtonLayout->SetValue(false);
	BoxSizer11->Add(CheckBoxButtonLayout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextVocalSynthesis = new wxStaticText(this, ID_STATICTEXT1, _("Vocal Synthesis"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticTextVocalSynthesis, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBoxVocalSynthesis = new wxCheckBox(this, ID_CHECKBOX1, _("On/Off"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBoxVocalSynthesis->SetValue(false);
	BoxSizer2->Add(CheckBoxVocalSynthesis, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextTimer = new wxStaticText(this, ID_STATICTEXT2, _("Popup Timer in s"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticTextTimer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlTimer = new wxSpinCtrl(this, ID_SPINCTRL1, _T("5"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 5, _T("ID_SPINCTRL1"));
	SpinCtrlTimer->SetValue(_T("5"));
	BoxSizer4->Add(SpinCtrlTimer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticButtonFontSize = new wxStaticText(this, ID_STATICTEXT4, _("Button Font Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer6->Add(StaticButtonFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlButtonFontSize = new wxSpinCtrl(this, ID_SPINCTRL3, _T("36"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 36, _T("ID_SPINCTRL3"));
	SpinCtrlButtonFontSize->SetValue(_T("36"));
	BoxSizer6->Add(SpinCtrlButtonFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticLabelFontSize = new wxStaticText(this, ID_STATICTEXT5, _("Label Font Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer7->Add(StaticLabelFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlLabelFontSize = new wxSpinCtrl(this, ID_SPINCTRL4, _T("36"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 36, _T("ID_SPINCTRL4"));
	SpinCtrlLabelFontSize->SetValue(_T("36"));
	BoxSizer7->Add(SpinCtrlLabelFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextPopupSizeRatio = new wxStaticText(this, ID_STATICTEXT8, _("Popup Size Ratio (%tage FullScreen)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer10->Add(StaticTextPopupSizeRatio, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlPopupSizeRatio = new wxSpinCtrl(this, ID_SPINCTRL5, _T("50"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 50, _T("ID_SPINCTRL5"));
	SpinCtrlPopupSizeRatio->SetValue(_T("50"));
	BoxSizer10->Add(SpinCtrlPopupSizeRatio, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	PopupLabelFontSize = new wxStaticText(this, ID_STATICTEXT3, _("Popup Label Font Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer5->Add(PopupLabelFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlPopupLabelFontSize = new wxSpinCtrl(this, ID_SPINCTRL2, _T("320"), wxDefaultPosition, wxDefaultSize, 0, 1, 600, 320, _T("ID_SPINCTRL2"));
	SpinCtrlPopupLabelFontSize->SetValue(_T("320"));
	BoxSizer5->Add(SpinCtrlPopupLabelFontSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextRedColorSelection = new wxStaticText(this, ID_STATICTEXT6, _("Red Color Selection"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer8->Add(StaticTextRedColorSelection, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonRedColorSelection = new wxButton(this, ID_BUTTON3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer8->Add(ButtonRedColorSelection, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticTextGreenColorSelection = new wxStaticText(this, ID_STATICTEXT7, _("Green Color Selection"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer9->Add(StaticTextGreenColorSelection, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonGreenColorSelection = new wxButton(this, ID_BUTTON4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer9->Add(ButtonGreenColorSelection, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ButtonCancel = new wxButton(this, ID_BUTTON1, _("Annuler"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(ButtonCancel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(ButtonOK, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserConfig::OnCheckBoxVocalSynthesisClick);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserConfig::OnCheckBoxVocalSynthesisClick);
	Connect(ID_SPINCTRL5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&UserConfig::OnSpinCtrlPopupLabelFontSizeChange);
	Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&UserConfig::OnSpinCtrlPopupLabelFontSizeChange);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UserConfig::OnButtonRedColorSelectionClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UserConfig::OnButtonGreenColorSelectionClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UserConfig::OnButtonCancelClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UserConfig::OnButtonOKClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&UserConfig::OnClose);
	//*)


    wxConfigBase *pConfig = wxConfigBase::Get();

    pConfig->SetRecordDefaults();

    CheckBoxButtonLayout->SetValue(pConfig->Read(_T("/UserPrefs/ButtonLayout"), 1l) != 0);
    CheckBoxVocalSynthesis->SetValue(pConfig->Read(_T("/UserPrefs/VocalSynthesis"), 1l) != 0);
    SpinCtrlTimer->SetValue(pConfig->Read(_T("/UserPrefs/Timer")));
    SpinCtrlButtonFontSize->SetValue(pConfig->Read(_T("/UserPrefs/ButtonFontSize")));
    SpinCtrlLabelFontSize->SetValue(pConfig->Read(_T("/UserPrefs/LabelFontSize")));
    SpinCtrlPopupSizeRatio->SetValue(pConfig->Read(_T("/UserPrefs/PopupSizeRatio")));
    SpinCtrlPopupLabelFontSize->SetValue(pConfig->Read(_T("/UserPrefs/PopupLabelFontSize")));
    ButtonRedColorSelection->SetBackgroundColour(wxColour(pConfig->Read(_T("/UserPrefs/ButtonRedColorSelection"))));
    ButtonGreenColorSelection->SetBackgroundColour(wxColour(pConfig->Read(_T("/UserPrefs/ButtonGreenColorSelection"))));

}

UserConfig::~UserConfig()
{
	//(*Destroy(UserConfig)
	//*)
}

bool UserConfig::GetVocalSynthesisValue()
{
    return CheckBoxVocalSynthesis->GetValue();
}

bool UserConfig::GetButtonLayoutValue()
{
    return CheckBoxButtonLayout->GetValue();
}


int UserConfig::GetTimerValue()
{
    return SpinCtrlTimer->GetValue();
}

int UserConfig::GetButtonFontSizeValue()
{
    return SpinCtrlButtonFontSize->GetValue();
}

int UserConfig::GetLabelFontSizeValue()
{
    return SpinCtrlLabelFontSize->GetValue();
}

int UserConfig::GetPopupSizeRatio()
{
    return SpinCtrlPopupSizeRatio->GetValue();
}

int UserConfig::GetPopupLabelFontSizeValue()
{
    return SpinCtrlPopupLabelFontSize->GetValue();
}

wxString UserConfig::GetButtonRedColorSelection()
{
    return (ButtonRedColorSelection->GetBackgroundColour()).GetAsString();
}

wxString UserConfig::GetButtonGreenColorSelection()
{
    return (ButtonGreenColorSelection->GetBackgroundColour()).GetAsString();
}

void UserConfig::OnButtonCancelClick(wxCommandEvent& event)
{
  wxConfigBase *pConfig = wxConfigBase::Get();
  if ( pConfig == NULL )
    return;

    CheckBoxButtonLayout->SetValue(pConfig->Read(_T("/UserPrefs/ButtonLayout"), 1l) != 0);
    CheckBoxVocalSynthesis->SetValue(pConfig->Read(_T("/UserPrefs/VocalSynthesis"), 1l) != 0);
    SpinCtrlTimer->SetValue(pConfig->Read(_T("/UserPrefs/Timer")));
    SpinCtrlButtonFontSize->SetValue(pConfig->Read(_T("/UserPrefs/ButtonFontSize")));
    SpinCtrlLabelFontSize->SetValue(pConfig->Read(_T("/UserPrefs/LabelFontSize")));
    SpinCtrlPopupSizeRatio->SetValue(pConfig->Read(_T("/UserPrefs/PopupSizeRatio")));
    SpinCtrlPopupLabelFontSize->SetValue(pConfig->Read(_T("/UserPrefs/PopupLabelFontSize")));
    ButtonRedColorSelection->SetBackgroundColour(wxColour(pConfig->Read(_T("/UserPrefs/ButtonRedColorSelection"))));
    ButtonGreenColorSelection->SetBackgroundColour(wxColour(pConfig->Read(_T("/UserPrefs/ButtonGreenColorSelection"))));



    this->Hide();
}

void UserConfig::OnButtonOKClick(wxCommandEvent& event)
{
  wxConfigBase *pConfig = wxConfigBase::Get();
  if ( pConfig == NULL )
    return;

  // save the control's values to the config
  pConfig->Write(_T("/UserPrefs/ButtonLayout"), CheckBoxButtonLayout->GetValue());
  pConfig->Write(_T("/UserPrefs/VocalSynthesis"), CheckBoxVocalSynthesis->GetValue());
  pConfig->Write(_T("/UserPrefs/Timer"), SpinCtrlTimer->GetValue());
  pConfig->Write(_T("/UserPrefs/ButtonFontSize"), SpinCtrlButtonFontSize->GetValue());
  pConfig->Write(_T("/UserPrefs/LabelFontSize"), SpinCtrlLabelFontSize->GetValue());
  pConfig->Write(_T("/UserPrefs/PopupSizeRatio"), SpinCtrlPopupSizeRatio->GetValue());
  pConfig->Write(_T("/UserPrefs/PopupLabelFontSize"), SpinCtrlPopupLabelFontSize->GetValue());
  pConfig->Write(_T("/UserPrefs/ButtonRedColorSelection"), (ButtonRedColorSelection->GetBackgroundColour()).GetAsString());
  pConfig->Write(_T("/UserPrefs/ButtonGreenColorSelection"), (ButtonGreenColorSelection->GetBackgroundColour()).GetAsString());
  this->Hide();

  wxString msg = _("Please restart LotoClic to activate the new preferences.\n");;//wxbuildinfo(long_f);
  wxMessageBox(msg, _("Restart LotoClic"));


}

void UserConfig::OnClose(wxCloseEvent& event)
{
    this->OnButtonCancelClick((wxCommandEvent&)event);
}

void UserConfig::OnCheckBoxVocalSynthesisClick(wxCommandEvent& event)
{
    //if (CheckBoxVocalSynthesis->IsChecked())
}

void UserConfig::OnSpinCtrlPopupLabelFontSizeChange(wxSpinEvent& event)
{
}

void UserConfig::OnButtonRedColorSelectionClick(wxCommandEvent& event)
{
  wxButton *RedColorButton = (wxButton*)event.GetEventObject();
  wxColourData data;
  data.SetChooseFull(true);
/*
  for (int i = 0; i < 16; i++)
  {
    wxColour colour(i*16, i*16, i*16);
    data.SetCustomColour(i, colour);
  }
*/
  wxColourDialog dialog(this, &data);
  if (dialog.ShowModal() == wxID_OK)
  {
    wxColourData retData = dialog.GetColourData();
    wxColour col = retData.GetColour();
    RedColorButton->SetBackgroundColour(col);
//    wxBrush brush(col, wxSOLID);
//    this->SetBackground(brush);
//    this->Clear();
//    this->Refresh();
  }
}

void UserConfig::OnButtonGreenColorSelectionClick(wxCommandEvent& event)
{
      wxButton *RedColorButton = (wxButton*)event.GetEventObject();
  wxColourData data;
  data.SetChooseFull(true);
/*
  for (int i = 0; i < 16; i++)
  {
    wxColour colour(i*16, i*16, i*16);
    data.SetCustomColour(i, colour);
  }
*/
  wxColourDialog dialog(this, &data);
  if (dialog.ShowModal() == wxID_OK)
  {
    wxColourData retData = dialog.GetColourData();
    wxColour col = retData.GetColour();
    RedColorButton->SetBackgroundColour(col);
//    wxBrush brush(col, wxSOLID);
//    this->SetBackground(brush);
//    this->Clear();
//    this->Refresh();
  }
}
