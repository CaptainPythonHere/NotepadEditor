#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextCursor>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_toggle_triggered(bool checked);

    void on_actionItalicise_triggered(bool checked);

    void on_actionUnderline_triggered(bool checked);

    void on_actionSuperScript_triggered(bool checked);

    void on_actionSubScript_triggered(bool checked);

private:
    Ui::Notepad *ui;
    QString currentFile;
};
#endif // NOTEPAD_H
