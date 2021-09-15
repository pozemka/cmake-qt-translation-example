#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QString test = QObject::tr("Hello!");

    qDebug("%s", qPrintable(test));

    return a.exec();
}
