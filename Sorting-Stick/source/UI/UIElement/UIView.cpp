#include "UI/UIElement/UIView.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Graphics;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::update() {}

		void UIView::render() {}

		void UIView::show() { ui_state = UIState::VISIBLE; }

		void UIView::hide() { ui_state = UIState::HIDDEN; }

		sf::Vector2f UIView::getPositionForCurrentResolution(sf::Vector2f position)
		{
			sf::Vector2f reference_resolution = ServiceLocator::getInstance()->getGraphicService()->getReferenceResolution();

			float adjusted_x_position = (position.x / reference_resolution.x) * game_window->getSize().x;
			float adjusted_y_position = (position.y / reference_resolution.y) * game_window->getSize().y;

			return sf::Vector2f(adjusted_x_position, adjusted_y_position);
		}

		sf::Vector2f UIView::getScaleForCurrentResolution(float width, float height)
		{
			sf::Vector2f reference_resolution = ServiceLocator::getInstance()->getGraphicService()->getReferenceResolution();

			float adjusted_width = (width / reference_resolution.x) * game_window->getSize().x;
			float adjusted_height = (height / reference_resolution.y) * game_window->getSize().y;

			return sf::Vector2f(adjusted_width, adjusted_height);
		}
	}
}