#include "UI/FloatSlider.h"
#include <QHBoxLayout>
#include <math.h>
FloatSlider::FloatSlider(float* const value, float min, float max, int _precision, Qt::Orientation orientation) : targetValue(value), minValue(min), maxValue(max)
{
	*value = std::clamp(*value, min, max);
	unit = _precision < 5 ? static_cast<int>(powf(10, _precision)) : static_cast<int>(powf(10, 5));
	
	CreateSlider(*value, orientation);
	CreateSpinBox(*value, _precision);

	QHBoxLayout* layout = new QHBoxLayout(this);
	layout->addWidget(slider);
	layout->addWidget(spinBox);
}

FloatSlider::~FloatSlider()
{
	
}

#pragma region private function
void FloatSlider::CreateSlider(float value, Qt::Orientation orientation) {
	slider = new QSlider(orientation);
	slider->setRange(0, unit);
	int convertedValue = 0;
	if (minValue != maxValue) convertedValue = ValueToSlider(value);
	else convertedValue = minValue;
	slider->setValue(convertedValue);
	connect(slider, &QSlider::valueChanged, this, &FloatSlider::SetSliderValue);
}

void FloatSlider::CreateSpinBox(float value, float precision) {
	spinBox = new QDoubleSpinBox();
	spinBox->setMinimum(minValue);
	spinBox->setMaximum(maxValue);
	spinBox->setMinimumWidth(98);
	spinBox->setDecimals(precision);
	spinBox->setSingleStep(1.0f / unit);
	spinBox->setValue(value);
	connect(spinBox, &QDoubleSpinBox::valueChanged, this, &FloatSlider::SetSpinBoxValue);
}

float FloatSlider::SliderToValue(int val) {
	float t = float(val) / unit;
	return minValue * (1 - t) + maxValue * t;
}
int FloatSlider::ValueToSlider(float val) {
	float t = (val - minValue) / (maxValue - minValue);
	return static_cast<int>(t * unit);
}

void FloatSlider::SetSliderValue(int v) {
	float result = SliderToValue(v);
	*targetValue = result;
	QSignalBlocker signalBolck(spinBox);
	spinBox->setValue(result);
}

void FloatSlider::SetSpinBoxValue(float val) {
	int result = ValueToSlider(val);
	slider->setValue(result);
}
#pragma endregion
