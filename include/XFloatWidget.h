#ifndef FLOATWIDGET_H
#define FLOATWIDGET_H

#include "XGuiGlobal.h"
#include "QtHelper/XQWidget.h"

class QHBoxLayout;
class QDoubleSpinBox;
class QSlider;

class EKSGUI_EXPORT XFloatWidget : public QWidget
    {
    Q_OBJECT

public:
    XFloatWidget( QWidget *parent = 0, qreal val = 0.0f );
    XFloatWidget( qreal val, qreal min, qreal max, QWidget *parent = 0 );

    void setMaximum( double );
    double maximum() const;
    void setMinimum( double );
    double minimum() const;
    double range() const;
    double value() const;
    void forceValue( double );

    bool isReadOnly() const;

Q_SIGNALS:
    void valueChanged( double );
    void valueChanged( XFloatWidget * );

public Q_SLOTS:
    void setValue( double );
    void setReadOnly(bool);

private Q_SLOTS:
    void setValueFromSlider( int );
    void setValueFromSpinner( double );

private:
    void setSliderFromValue( double );
    qreal usedMaximum() const;
    qreal usedMinimum() const;
    double usedRange() const;
    void updateUsed();
    QHBoxLayout *_layout;
    QDoubleSpinBox *_spinner;
    QSlider *_slider;
    double _usedMinimum;
    double _usedMaximum;
    bool _setting;
    bool _settingValue;
    bool _settingSlider;
    };

#endif // FLOATWIDGET_H
