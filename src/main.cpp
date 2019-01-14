#include    "main.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file("../data/questions.txt");

    if (!file.open(QIODevice::ReadOnly))
        return -1;

    QTextStream stream(&file);

    QMap<int, QString> questions;

    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList tokens = line.split('.');

        int num = tokens[0].toInt();

        questions.insert(num, tokens[1]);
    }

    QPdfWriter writer("../data/tickets.pdf");
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&writer);
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPixelSize(90);
    painter.setFont(font);

    QMap<int, QString>::iterator it = questions.begin();

    int y = 0;

    for (; it != questions.end(); ++it)
    {
        QString str = QString("%1. %2").arg(it.key()).arg(it.value());
        painter.drawText(0, y, str);
        y += 100;
    }

    painter.end();


    return 0;
}
