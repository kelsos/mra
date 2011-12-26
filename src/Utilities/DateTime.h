#ifndef DATETIME_H
#define DATETIME_H
#include <QtDebug>
#include <QDateTime>
#include <QString>

class DateTime
{
public:
	static QDateTime parseRFC822DateTime(QString rfc822);
protected:
private:
	static int convertTimeZoneToHours(QString timeZone);
	static int convertShortMonthToInt(QString month);
};

#endif