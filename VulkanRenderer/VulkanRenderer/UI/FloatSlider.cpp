#include "UI/FloatSlider.h"
#include <math.h>
FloatSlider::FloatSlider(float* const value, float min, float max, int _precision, Qt::Orientation orientation) :QSlider(orientation), targetValue(value), minValue(min), maxValue(max)
{
	*value = std::clamp(*value, min, max);
	unit = _precision < 5 ? static_cast<int>(powf(10, _precision)) : static_cast<int>(powf(10, 5));
	setRange(0, unit);
	float t = 0;
	if (min != max) t = (*value - min) / (max - min);
	else t = 0;

	setValue(static_cast<int>(t * unit));
	connect(this, &QSlider::valueChanged, this, &FloatSlider::SetValue);
}

FloatSlider::~FloatSlider()
{

}

#pragma region private function
float FloatSlider::ProcessingValue(int v) {
	float t = float(v) / unit;
	return minValue * (1 - t) + maxValue * t;
}

void FloatSlider::SetValue(int v) {
	*targetValue = ProcessingValue(v);
}
#pragma endregion
