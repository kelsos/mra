#include "MangaSqlQueryModel.h"

MangaSqlQueryModel::MangaSqlQueryModel(QObject *parent):QSqlQueryModel(parent)
{

}

QVariant MangaSqlQueryModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index,role);
	if(value.isValid()&&role== Qt::DisplayRole)
	{
		if (index.column()==4)
		{
		    QDateTime lastReadDate=value.toDateTime();
			return lastReadDate.toString("yyyy-MM-dd");
		}
		if (index.column()==5)
		{
			if(value.toBool())
			{
				return "Yes";
			}
			else
			{
				return "No";
			}
		}
	}
	return QSqlQueryModel::data(index, role);
}