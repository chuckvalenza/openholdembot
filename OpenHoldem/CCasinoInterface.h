//******************************************************************************
//
// This file is part of the OpenHoldem project
//   Download page:         http://code.google.com/p/openholdembot/
//   Forums:                http://www.maxinmontreal.com/forums/index.php
//   Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose:
//
//******************************************************************************

#ifndef INC_CCASINOINTERFACE_H
#define INC_CCASINOINTERFACE_H

#include "CAllinSlider.h"
#include "CAutoplayerButton.h"
#include "CBetsizeInputBox.h"
#include "CCasinoHotkeys.h"
#include "MagicNumbers.h"

class CCasinoInterface {
  friend class CAutoplayer;
  friend class CScraper;
  friend class CSymbolEngineAutoplayer;
 public:
	CCasinoInterface();
	~CCasinoInterface();
 public: //!!!!!
	//bool ClickButton(int autoplayer_function_code);
	//bool ButtonAvailable(int autoplayer_code);
	//bool ButtonClickable(int autoplayer_code);
	bool ClickButtonSequence(int first_button, int second_button, int delay_in_milli_seconds);
	bool EnterBetsize(double total_betsize_in_dollars);
  bool EnterBetsizeForAllin();
	bool UseSliderForAllin();
	bool CloseWindow();
	bool EnterChatMessage(CString &message);
	int  NumberOfVisibleAutoplayerButtons();
  bool IsMyTurn();
  void PressTabToSwitchOHReplayToNextFrame();
  bool HandleInterfacebuttonsI86();
 private:
	bool TableLostFocus();
	void ClickRect(RECT rect);
	void SelectSwagText();
	void DeleteSwagText();
 private:
	POINT p_null;
	RECT r_null; 
	// ToDo: Sliderbar, Chatbox, etc.
 public:
  // For logical lookup of buttons
  CAutoplayerButton* LogicalAutoplayerButton(int autoplayer_function_code);
  CAutoplayerButton* LogicalAutoplayerButton(CString ButtonLabel);
  CAutoplayerButton* BetsizeConfirmationButton();
 public:
  bool AllinOptionAvailable();
 protected:
  // To be used by the scraper
  CAutoplayerButton _technical_autoplayer_buttons[k_max_number_of_buttons];
  CAutoplayerButton _technical_betpot_buttons[k_max_betpot_buttons];
  CAutoplayerButton _technical_i86X_spam_buttons[k_max_number_of_i86X_buttons];
  CAllinSlider _allin_slider;
 private:
  CBetsizeInputBox _betsize_input_box;
 public:
	// regions 
	//!!!!!RECT action_buttons[k_number_of_standard_functions];
	//RECT i3_button;
	//RECT i3_edit_region;
	//RECT i3_slider_region;
	//RECT i3_handle_region;
	//RECT i86X_button[k_max_number_of_i86X_buttons];
 private:
  CCasinoHotkeys casino_hotkeys;
}; 

extern CCasinoInterface *p_casino_interface;

#endif // INC_CCasinoInterface_H