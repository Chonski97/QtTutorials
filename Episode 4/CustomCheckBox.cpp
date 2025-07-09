#include "CustomCheckBox.h"

CustomCheckBox::CustomCheckBox(QWidget* parent) : QCheckBox(parent)
{

}

CustomCheckBox::CustomCheckBox(QString const& text, QWidget* parent) : QCheckBox(parent)
{
	setText(text);
}