#include "main.h"

bool Game::EventReceiverClass::OnEvent(const SEvent &TEvent) {
		if(TEvent.EventType == EET_KEY_INPUT_EVENT && !TEvent.KeyInput.PressedDown) {
			switch(TEvent.KeyInput.Key) {
				case KEY_ESCAPE:
				std::cout << "exited." << std::endl;
				runn=false;
				break;
			}
			return false;
		}
		return false;
	}
