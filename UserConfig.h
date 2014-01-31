#ifndef USERCONFIG_H
#define USERCONFIG_H
#include <wx/config.h>

//(*Headers(UserConfig)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class UserConfig: public wxFrame
{
	public:

		UserConfig(wxWindow* parent,wxWindowID id=wxID_ANY);
		bool GetVocalSynthesisValue();
		bool GetButtonLayoutValue();
		int GetTimerValue();
		int GetButtonFontSizeValue();
		int GetLabelFontSizeValue();
		int GetPopupSizeRatio();
		int GetPopupLabelFontSizeValue();
		wxString GetButtonRedColorSelection();
		wxString GetButtonGreenColorSelection();



		virtual ~UserConfig();

		//(*Declarations(UserConfig)
		wxSpinCtrl* SpinCtrlLabelFontSize;
		wxButton* ButtonOK;
		wxStaticText* StaticTextGreenColorSelection;
		wxButton* ButtonRedColorSelection;
		wxSpinCtrl* SpinCtrlTimer;
		wxSpinCtrl* SpinCtrlPopupSizeRatio;
		wxCheckBox* CheckBoxVocalSynthesis;
		wxStaticText* StaticLabelFontSize;
		wxButton* ButtonCancel;
		wxButton* ButtonGreenColorSelection;
		wxStaticText* PopupLabelFontSize;
		wxSpinCtrl* SpinCtrlPopupLabelFontSize;
		wxStaticText* StaticTextRedColorSelection;
		wxStaticText* StaticTextPopupSizeRatio;
		wxStaticText* StaticTextTimer;
		wxCheckBox* CheckBoxButtonLayout;
		wxStaticText* StaticTextVocalSynthesis;
		wxStaticText* StaticButtonFontSize;
		wxStaticText* StaticTextButtonLayout;
		wxSpinCtrl* SpinCtrlButtonFontSize;
		//*)

	protected:

		//(*Identifiers(UserConfig)
		static const long ID_STATICTEXT9;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT8;
		static const long ID_SPINCTRL5;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT7;
		static const long ID_BUTTON4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(UserConfig)
		void OnButtonCancelClick(wxCommandEvent& event);
		void OnButtonOKClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnCheckBoxVocalSynthesisClick(wxCommandEvent& event);
		void OnSpinCtrlPopupLabelFontSizeChange(wxSpinEvent& event);
		void OnButtonRedColorSelectionClick(wxCommandEvent& event);
		void OnButtonGreenColorSelectionClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
