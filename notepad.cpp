#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::on_actionNew_triggered()
{

        currentFile.clear();
        ui->textEdit->setText(QString());
}


void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
     {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
     }
     setWindowTitle(fileName);
     QTextStream in(&file);
     QString text = in.readAll();
     ui->textEdit->setText(text);
     file.close();
}


void Notepad::on_actionSave_triggered()
{
    QString fileName;
    if (currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "Save", ".txt");
        currentFile = fileName;
    }
    else
    {
        fileName = currentFile;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}


void Notepad::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

   if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning","Can't Open this file!" + file.errorString());
       return;
    }

    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}


void Notepad::on_actionPrint_triggered()
{
    QPrinter printDev;
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
    ui->textEdit->print(&printDev);
}


void Notepad::on_actionExit_triggered()
{
     QCoreApplication::quit();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}





void Notepad::on_actionBold_toggle_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setFontWeight(QFont::Bold);
    else
        format.setFontWeight(QFont::Normal);

    if(ui->textEdit->hasFocus())
    ui->textEdit->mergeCurrentCharFormat(format);
}


void Notepad::on_actionItalicise_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setFontItalic(QFont::StyleItalic);
    else
        format.setFontItalic(QFont::StyleNormal);

    if(ui->textEdit->hasFocus())
    ui->textEdit->mergeCurrentCharFormat(format);
}


void Notepad::on_actionUnderline_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setFontUnderline(true);
    else
        format.setFontUnderline(false);

    if(ui->textEdit->hasFocus())
    ui->textEdit->mergeCurrentCharFormat(format);
}


void Notepad::on_actionSuperScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    if(ui->textEdit->hasFocus())
    ui->textEdit->mergeCurrentCharFormat(format);
}


void Notepad::on_actionSubScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    if(ui->textEdit->hasFocus())
    ui->textEdit->mergeCurrentCharFormat(format);
}

