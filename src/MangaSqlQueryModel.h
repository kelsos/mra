#ifndef MANGASQLQUERYMODEL_H
#define MANGASQLQUERYMODEL_H

#include <QSqlQueryModel>
#include <QVariant>
#include <QDateTime>

class MangaSqlQueryModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	MangaSqlQueryModel(QObject *parent=0);
	QVariant data(const QModelIndex &item, int role) const;
};
#endif