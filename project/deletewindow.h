#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>
#include "data/graph.h"

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(Graph* g, QWidget *parent = nullptr);
    ~DeleteWindow();

signals:
    void VertexDeleted(Vertex *v);
    void EdgeDeleted(Edge *e);


private slots:
    void on_VertexDel_clicked();

    void on_EdgeDel_clicked();

private:
    Ui::DeleteWindow *ui;
    Graph* graph;
};

#endif // DELETEWINDOW_H
