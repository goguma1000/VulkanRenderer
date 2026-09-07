#pragma once
#include <QSlider>
class FloatSlider : public QSlider
{
	Q_OBJECT
public:
	FloatSlider(float* const value, float min, float max, int _precision = 3, Qt::Orientation orientation = Qt::Orientation::Horizontal);
	~FloatSlider();

private:

	void SetValue(int v);
	float ProcessingValue(int v);
	int unit = 1;
	float minValue = 0;
	float maxValue = 0;
	float* targetValue = nullptr;
};

