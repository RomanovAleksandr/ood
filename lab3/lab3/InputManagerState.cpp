#include "InputManagerState.h"
#include "InputManager.h"

void DragAndDropState::Execute()
{
	context_->m_shapesManager.selectedShape->Move(context_->mouseOffset);
}
void ChangeShapeColorState::Execute()
{
	context_->m_shapesManager.selectedShape->SetFillColor(context_->selectedColor);
}