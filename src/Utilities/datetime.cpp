#include "datetime.h"

QDateTime DateTime::parseRFC822DateTime(QString rfc822)
{
    QString dateTimeString;
    QString timeZoneString;
    QDateTime internalDateTime;
    int timeZoneHours;

    if(rfc822.length()==31)
    {
        timeZoneHours = rfc822.right(5).toInt()/100;
        //qDebug() << timeZoneHours;
    }
    else
    {
        timeZoneString = rfc822.right(rfc822.length()-25).trimmed();
        //qDebug() << timeZoneString;
        timeZoneHours = convertTimeZoneToHours(timeZoneString);
        //qDebug() << timeZoneHours << "From ABBR";
    }

    dateTimeString = rfc822.left(25).right(20);
    dateTimeString.replace(dateTimeString.left(6).right(3), QString::number(convertShortMonthToInt(dateTimeString.left(6).right(3))));
    internalDateTime = QDateTime::fromString(dateTimeString, "dd MM yyyy hh:mm:ss");
    internalDateTime = internalDateTime.addSecs(timeZoneHours*60*60*-1);
    internalDateTime.setTimeSpec(Qt::UTC);
    //qDebug() << internalDateTime.toUTC().toString(Qt::ISODate);
    return internalDateTime.toLocalTime();
}

//Can be expanded later to support even more timezones;
int DateTime::convertTimeZoneToHours(QString timeZone)
{
    if(timeZone=="GMT")
        return 0;
    else if (timeZone=="UT")
        return 0;
    else if (timeZone=="EDT")
        return -4;
    else if (timeZone=="EST"||timeZone=="CDT")
        return -5;
    else if (timeZone=="CST"||timeZone=="MDT")
        return -6;
    else if (timeZone=="MST"||timeZone=="PDT")
        return -7;
    else if (timeZone=="PST")
        return -8;
    else
        return 0;
}

int DateTime::convertShortMonthToInt(QString month)
{
    if (month == "Jan")
        return 1;
    else if (month == "Feb")
        return 2;
    else if (month == "Mar")
        return 3;
    else if (month == "Apr")
        return 4;
    else if (month == "May")
        return 5;
    else if (month == "Jun")
        return 6;
    else if (month == "Jul")
        return 7;
    else if (month == "Aug")
        return 8;
    else if (month == "Sep")
        return 9;
    else if (month == "Oct")
        return 10;
    else if (month == "Nov")
        return 11;
    else if (month == "Dec")
        return 12;
    else
        return -1;
}
