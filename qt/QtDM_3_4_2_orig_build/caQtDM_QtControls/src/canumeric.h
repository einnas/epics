//******************************************************************************
// Copyright (c) 2012 Paul Scherrer Institut PSI), Villigen, Switzerland
// Disclaimer: neither  PSI, nor any of their employees makes any warranty
// or assumes any legal liability or responsibility for the use of this software
//******************************************************************************
//******************************************************************************
//
//     Author : Anton Chr. Mezger
//
//******************************************************************************

#ifndef CANUMERIC_H
#define CANUMERIC_H

#include <QWidget>
#include <qtcontrols_global.h>
#include <enumeric.h>

class QTCON_EXPORT caNumeric : public ENumeric
{
Q_OBJECT

    Q_PROPERTY(QString channel READ getPV WRITE setPV)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    Q_PROPERTY(SourceMode precisionMode READ getPrecisionMode WRITE setPrecisionMode)
    Q_PROPERTY(bool fixedFormat READ getFixedFormat WRITE setFixedFormat)

    Q_PROPERTY(SourceMode limitsMode READ getLimitsMode WRITE setLimitsMode)
    Q_ENUMS(SourceMode)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)

public:

     caNumeric(QWidget *parent);
    ~caNumeric(){}

    QString getPV() const;
    void setPV(QString const &newPV);

    int getAccessW() const {return thisAccessW;}
    void setAccessW(int access);

    enum SourceMode {Channel = 0, User};
    SourceMode getPrecisionMode() const { return thisPrecMode; }
    void setPrecisionMode(SourceMode precmode) {thisPrecMode = precmode;}
    SourceMode getLimitsMode() const { return thisLimitsMode; }

    bool getFixedFormat()  const {return thisFixedFormat;}
    void setFixedFormat(bool const &fixed) {thisFixedFormat=fixed;}

    void setLimitsMode(SourceMode limitsmode) { thisLimitsMode = limitsmode;}

    double getMaxValue()  const {return thisMaximum;}
    void setMaxValue(double const &maxim) {thisMaximum=maxim; setMaximum(maxim);}

    double getMinValue()  const {return thisMinimum;}
    void setMinValue(double const &minim) {thisMinimum=minim; setMinimum(minim);}

    QColor getForeground() const {return thisForeColor;}
    void setForeground(QColor c);

    QColor getBackground() const {return thisBackColor;}
    void setBackground(QColor c);

    void setColors(QColor bg, QColor fg);
    void setConnectedColors(bool connected);



private:


    QString thisPV;
    bool thisAccessW;
    double thisMaximum, thisMinimum;
    SourceMode thisPrecMode;
    SourceMode thisLimitsMode;
    bool thisFixedFormat;
    QColor thisForeColor, oldForeColor;
    QColor thisBackColor, oldBackColor;
    bool _perm;
};
#endif
