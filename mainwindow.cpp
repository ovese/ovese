#include "mainwindow.h"
#include "shapefil.h"

MainWindow::MainWindow(QWidget *parent) : QDialog(parent)
{


    setWindowTitle(tr("Shape File Display"));
//    resize(500, 400);
    setMinimumSize(500,400);


    QLabel *lbl_shapefile=new QLabel(tr("Select Shape file: "));

    QStringList strlst= (QStringList()<<""<<"default "<<"test1.sh"<<"test2.sh"<<"test3.sh");
    qcb=new QComboBox();
    qcb->addItems(strlst);

    QHBoxLayout *lo_shapesel=new QHBoxLayout();
    lo_shapesel->addWidget(lbl_shapefile);
    lo_shapesel->addWidget(qcb);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    imageLabel->setScaledContents(true);
//    QString img_placeholder="C:\\Users\\Knowdyn\\Desktop\\Copied\\Ese\\Tekkaboki\\ikore_cirad\\ShapeTest\\dummyshape.png";
//    QPixmap image(img_placeholder);
//    imageLabel->setPixmap(image);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->sizeHint();



    //setCentralWidget(scrollArea);

    QVBoxLayout *mainlayout=new QVBoxLayout();
    mainlayout->addLayout(lo_shapesel);
    mainlayout->addWidget(imageLabel);
    mainlayout->addWidget(scrollArea);

    setLayout(mainlayout);

    connect(qcb, SIGNAL(currentIndexChanged(int)),this,SLOT(onComboboxCurrentIndexChanged()));
//    connect(qcb, SIGNAL(currentIndexChanged(const QString &text)),this,SLOT(onComboboxCurrentIndexChanged(const QString &text)));
//    connect(qcb, SIGNAL(currentIndexChanged(const QString &text)),this,SLOT(onComboboxCurrentTextChanged(const QString &text)));


}

MainWindow::~MainWindow()
{
}

void MainWindow::onComboboxCurrentIndexChanged(){
    if(qcb->currentIndex()==1){
        QString img_placeholder="C:\\Users\\Knowdyn\\Desktop\\Copied\\Ese\\Tekkaboki\\ikore_cirad\\ShapeTest\\dummyshape.png";
        //I think I can use render here before QPixmap
        QPixmap image(img_placeholder);
        imageLabel=new QLabel();
        imageLabel->setPixmap(image);
        scrollArea->setWidget(imageLabel);

    }
    else if(qcb->currentIndex()==2){
        ptr_shp1=new QChar();
        QString str_shp1="Other files\\strassen.shp";



        //Function to Open Shapefile and parse the info
//        OpenShapeFile(&str_shp1);//Line Shapefile
//        OpenShapeFile("Shapefiles\\poi.shp");//Point Shapefile
//        OpenShapeFile("Shapefiles\\gruenflaechen.shp");//Polygon Shapefile


    }
    else if(qcb->currentIndex()==3){


    }
    else if(qcb->currentIndex()==4){


    }

}

void MainWindow::onComboboxCurrentIndexChanged(const QString &text){

}

void MainWindow::onComboboxCurrentTextChanged(const QString &text){

}

typedef struct MyPoint2D
{
 double dX;
 double dY;

}MyPoint2D;

//Holds Coordinates of Point Shapefile
QVector<MyPoint2D> vPoints;

typedef struct MyLineString2D
{
QVector<MyPoint2D> vPointList;

}MyLineString2D;

//Holds Coordinates of Line Shapefile
QVector<MyLineString2D> vLines;


typedef struct MyPolygon2D
{
QVector<MyPoint2D> vPointList;

}MyPolygon2D;
//Holds Coordinates of Polygon Shapefile
QVector<MyPolygon2D> vPolygons;



typedef struct SBoundingBox
{
 float fMaxX;
 float fMaxY;
 float fMinX;
 float fMinY;

}SBoundingBox;
//Bounding Box of Shapefile
SBoundingBox sBoundingBox;

//Function to Open Shapefile and parse the info
void MainWindow::OpenShapeFile(QChar *fileName)
{

//    SHPHandle hSHP=SHPOpen(fileName, "rb" );

//    //Read Bounding Box of Shapefile
//    sBoundingBox.fMaxX=hSHP->adBoundsMax[0];
//    sBoundingBox.fMaxY=hSHP->adBoundsMax[1];

//    sBoundingBox.fMinX=hSHP->adBoundsMin[0];
//    sBoundingBox.fMinY=hSHP->adBoundsMin[1];


//    if(hSHP == NULL) return;

//    //Point Shapefile
//    if(hSHP->nShapeType == SHPT_POINT)
//    {
//        SHPObject *psShape;
//        for(int i=0;i<hSHP->nRecords;i++)
//        {
//            psShape = SHPReadObject(hSHP, i);

//            double fX = psShape->padfX[0];
//            double fY = -psShape->padfY[0];

//            //Plot these points
//            MyPoint2D pt;
//            pt.dX=fX;
//            pt.dY=-fY;
//            vPoints.push_back(pt);
//        }
//    }


//    //Line Shapefile
//    else if(hSHP->nShapeType == SHPT_ARC)
//    {
//        SHPObject *psShape;
//        for(int i=0;i<hSHP->nRecords;i++)
//        {
//            psShape = SHPReadObject(hSHP, i);
//            QVector<MyPoint2D> tempPointArray;

//            for(int j=0;j<psShape->nVertices;j++)
//            {
//                double fX = psShape->padfX[j];
//                double fY = psShape->padfY[j];
//                MyPoint2D pt;
//                pt.dX=fX;
//                pt.dY=fY;
//                tempPointArray.push_back(pt);
//            }

//            MyLineString2D linestring;
//            linestring.vPointList=tempPointArray;
//            vLines.push_back(linestring);

//        }
//    }

//    //Polygon Shapefile
//    if(hSHP->nShapeType == SHPT_POLYGON)
//    {
//        SHPObject *psShape;
//        for(int i=0;i<hSHP->nRecords;i++)
//        {
//            psShape = SHPReadObject(hSHP, i);
//            QVector<MyPoint2D> tempPointArray;

//            for(int j=0;j<psShape->nVertices;j++)
//            {
//                double fX = psShape->padfX[j];
//                double fY = psShape->padfY[j];
//                MyPoint2D pt;
//                pt.dX=fX;
//                pt.dY=fY;
//                tempPointArray.push_back(pt);
//            }
//            MyPolygon2D polygon;
//            polygon.vPointList=tempPointArray;
//            vPolygons.push_back(polygon);
//        }

//    }

}//ends openshapefile

void MainWindow::draw()
{

//    glClear (GL_COLOR_BUFFER_BIT);
//    glColor3f (0.0, 0.0, 1.0);
//    glLoadIdentity ();

//    //Render Point Shapefile
//    glColor3f (0.0, 0.0, 1.0);
//    glEnable(GL_POINT_SMOOTH) ;
//    glPointSize(5.0);
//    glBegin(GL_POINTS);

//    for(int i=0;i<vPoints.size();i++)
//    {
//        glVertex2f(vPoints[i].dX,vPoints[i].dY);
//    }

//    glEnd();

//    //Render Line Shapefile
//    glColor3f (0.0, 1.0, 0.0);
//    for( quint8 i=0;i<vLines.size();i++)
//    {

//        glBegin(GL_LINE_STRIP);
//        for(int j=0;j<vLines[i].vPointList.size();j++)
//        {
//          glVertex2f(vLines[i].vPointList[j].dX,vLines[i].vPointList[j].dY);

//        }

//        glEnd();
//    }

//    //Render Polygon Shapefile
//    glColor3f(1.0,0.0, 0.0);
//    for(quint8 i=0;i<vPolygons.size();i++)
//    {
//        glBegin(GL_LINE_LOOP);
//        for(int j=0;j<vPolygons[i].vPointList.size();j++)
//        {
//            glVertex2f(vPolygons[i].vPointList[j].dX,vPolygons[i].vPointList[j].dY);
//        }

//        glEnd();
//    }

//   glFlush();
}

void MainWindow::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}



