#include "CustomTableModel.h"

CustomTableModel::CustomTableModel(QObject* parent) : QAbstractTableModel(parent)
{
}

int CustomTableModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid())
		return 0;
	return 5;
}

int CustomTableModel::columnCount(const QModelIndex& parent) const
{
	if (parent.isValid())
		return 0;
	return 5;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::DisplayRole) {
		return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() + 1);
	}

	return QVariant();
}