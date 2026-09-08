#pragma once
#include <QSlider>
#include <QDoubleSpinBox>
class FloatSlider : public QWidget
{
	Q_OBJECT
public:
	FloatSlider(float* const value, float min, float max, int _precision = 3, Qt::Orientation orientation = Qt::Orientation::Horizontal);
	~FloatSlider();

private:
	QSlider* slider = nullptr;
	QDoubleSpinBox* spinBox = nullptr;
	void CreateSlider(float value, Qt::Orientation orientation);
	void CreateSpinBox(float value, float precision);
	void SetSliderValue(int val);
	void SetSpinBoxValue(float val);
	int ValueToSlider(float val);
	float SliderToValue(int val);
	int unit = 1;
	float minValue = 0;
	float maxValue = 0;
	float* targetValue = nullptr;
};

