#ifndef IMAGEPROCESSER_H
#define IMAGEPROCESSER_H
#include <QObject>
#include <QString>
static void binarize(QString src, QString dst) {
    return;
}

static void gray(QString src, QString dst) {
    return;
}

static void negative(QString src, QString dst) {

}

static void sharpen(QString src, QString dst) {

}

static void soften(QString src, QString dst) {

}

static void emboss(QString src, QString dst) {

}

class ImageProcessorPrivate;
class ImageProcessor : public QObject {
    Q_OBJECT
    Q_ENUMS(ImageAlgorithm)
    Q_PROPERTY(QString srcFile READ sourceFile)
    Q_PROPERTY(ImageAlgorithm algorithm READ getAlgorithm)

public:
    ImageProcessor(QObject *parent = 0) : QObject(parent) {}
    ~ImageProcessor(){}

    enum ImageAlgorithm {
        Gray = 0,
        Binarize,
        Negative,
        Emboss,
        Sharpen,
        Soften,
        AlgorithmCount
    };

    QString sourceFile() const {return srcFile;}
    ImageAlgorithm getAlgorithm() const {return algorithm;}
    void setTempPath(QString tempPath){}

signals:
    void finished(QString newFile);
    void progress(int value);

public slots:
    void process(QString file, ImageAlgorithm algorithm){}
    void abort(QString file, ImageAlgorithm algorithm){}

private:
    ImageProcessorPrivate *m_d;
    QString srcFile;
    ImageAlgorithm algorithm;
};

#endif // IMAGEPROCESSER_H
