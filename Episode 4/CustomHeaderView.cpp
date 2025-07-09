#include "CustomHeaderView.h"
#include <QSizePolicy>

CustomHeaderView::CustomHeaderView(Qt::Orientation orientation, QWidget* parent) : QHeaderView(orientation, parent)
{
	setHighlightSections(true);
	setSectionsClickable(true);
	setSectionsMovable(true);

	if (orientation == Qt::Horizontal) {
		setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
		setSectionResizeMode(QHeaderView::Stretch);
	}
}

void CustomHeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
{
	// Customize the header section appearance
	if (orientation() == Qt::Horizontal) {
		painter->drawText(rect, Qt::AlignCenter, QString("Column%1").arg(logicalIndex + 1));
	}
	else if (orientation() == Qt::Vertical) {
		painter->drawText(rect, Qt::AlignCenter, QString::number(logicalIndex + 1));
	}
}
