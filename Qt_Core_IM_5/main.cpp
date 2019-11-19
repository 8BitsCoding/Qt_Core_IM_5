#include <QtCore/QCoreApplication>

#include <qlist.h>
#include <qvector.h>
#include <qdebug.h>


template<class T>
void fill(T& container) {
	for (int i = 0; i < 5; i++) {
		container.append(i);
	}
}

template<class T>
void display(T& container) {
	for (int i = 0; i < container.length(); i++) {
		if (i > 0) {
			auto current = reinterpret_cast<std::uintptr_t>(&container.at(i));
			auto previous = reinterpret_cast<std::uintptr_t>(&container.at(i - 1));

			auto distance = current - previous;

			qInfo() << i << "At : " << current << "Previous : " << previous << "Distance : " << distance;
		}
		else {
			qInfo() << i << &container.at(i) << "Distance : 0";
		}
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QVector<int> vect = QVector<int>();
	QList<int> list = QList<int>();

	fill(vect);
	fill(list);

	qInfo() << "vector";
	display(vect);

	qInfo() << "list";
	display(list);

	qInfo() << "Int takes " << sizeof(int) << "bytes of ram";

	// QVector uses continuous location in memory
	// QList uses what ever it can find in memory

	return a.exec();
}

