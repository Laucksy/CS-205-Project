#include "textview.h"
#include "ui_textview.h"
#include <iostream>
using namespace std;


textView::textView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textView)
{

    ui->setupUi(this);

}

textView::~textView()
{
    delete ui;
}

void textView::makeComment(Code* myCode){
    myCode->insert(commentLoc);
    this->update();
}

//Code* textView::updateCode(string file)
//{

//    int tabCounter=0;
//   vector<string> lines;
//   bool comment=false;
//   bool lineComment=false;
//   bool bracket=false;

//   // ui->textBrowser->setSizePolicy();
//   QString code1="hi";
//   QString code2="there";
//   DBTool* tool = new DBTool("TestDB");
//   Code* x = new Code(tool,file,0);




//       cout << "Got here 1" << endl;

//       //vector<string> v;
//       vector<string> v = x->parse();
//       cerr<<v.size();
//       ui->textBrowser->setText("");
//       for(int i=0; i<v.size(); i++){   //lines

//           vector<string> t = x->tokenize(v[i]);
//           vector<string> delims = x->delimiters(v.at(i));
//           for(int a=0; a<t.size();a++){
//               string rawHTML = (a < delims.size()) ? delims.at(a) : " ";
//               QString qstr1 = QString::fromStdString(rawHTML);
//               ui->textBrowser->setTextColor("Cornsilk ");
//               ui->textBrowser->insertPlainText(qstr1);

//               QString qstr = QString::fromStdString(t[a]);
//               int type = x->categorize(t[a]);
//             //  int dtype = x->categorize()
//              // int delimType= x->categorize(delims[a]);
//               if(a==0&&type==11)
//               {
//                   lineComment=true;
//               }
//               else if(a==0&&type!=11)
//               {
//                   lineComment=false;
//               }

//              if(type==9){
//               comment=true;
//              }
//              if(type==10)
//              {
//                  comment=false;
//              }
//                   switch(type)
//                   {
//                   case 1:
//                       ui->textBrowser->setTextColor("Deepskyblue");
//                       break;
//                   case 2:
//                       ui->textBrowser->setTextColor("Mediumvioletred");
//                       break;
//                   case 3:
//                       ui->textBrowser->setTextColor("Mediumvioletred");
//                       break;
//                   case 4:
//                       ui->textBrowser->setTextColor("red");
//                       break;
//                   case 5:
//                       ui->textBrowser->setTextColor("red");
//                       break;
//                   case 6:
//                       ui->textBrowser->setTextColor("Dodgerblue");
//                       break;
//                   case 7:
//                       ui->textBrowser->setTextColor("Mediumvioletred");
//                       break;
//                   case 8:
//                       ui->textBrowser->setTextColor("Mediumvioletred");
//                       break;
//                   case 9:
//                       ui->textBrowser->setTextColor("green");
//                       break;
//                   case 10:
//                       ui->textBrowser->setTextColor("green");
//                       break;
//                   case 11:
//                       ui->textBrowser->setTextColor("green");
//                       break;
//                   case 12:
//                       tabCounter++;
//                       bracket=true;
//                       break;
//                   case 13:
//                       tabCounter--;
//                       break;
//                   case 0:
//                       ui->textBrowser->setTextColor("Cornsilk ");
//                       break;
//                   default:
//                       ui->textBrowser->setTextColor("Cornsilk ");
//                       break;
//                   }

//                   if(comment||lineComment)
//                   {
//                       ui->textBrowser->setTextColor("green");

//                   }

//                   if(a==0){

//                      // std::string temp = std::to_string(i);
//                      // QString nums = QString::fromStdString(temp);
//                     //  ui->textBrowser->insertPlainText(nums);
//                       //for(int tabs=0;tabs<tabCounter;tabCounter++){
//                       if(bracket){
//                           for(int tabs=0;tabs<tabCounter-1;tabs++)
//                           {
//                                   ui->textBrowser->insertPlainText("    ");

//                           }
//                           bracket=false;

//                       }
//                       else
//                       {

//                          for(int tabs=0;tabs<tabCounter;tabs++)
//                          {
//                                  ui->textBrowser->insertPlainText("    ");

//                          }
//                       }

//                      // }
//                   }

////                else{
////                    switch(delimType)
////                    {
////                    case 9:
////                        ui->textBrowser->setTextColor("green");
////                        break;
////                    case 0:
////                        ui->textBrowser->setTextColor("black");
////                        break;
////                    default:
////                        ui->textBrowser->setTextColor("black");
////                        break;
////                    }
////                }

//                   // ui->textBrowser->moveCursor(QTextCursor::End);
//                   // ui->textBrowser::moveCursor(  ui->textBrowser::End);
//                   ui->textBrowser->insertPlainText(qstr);
//                   //  ui->textBrowser->append(qstr);
//                  // cout << "Testing" << endl;
//               }
//               ui->textBrowser->append("");
//           }

//   return x;

//   }

Code* textView::updateCode(Code* myCode)
{

     ui->textBrowser->clear();
   int tabCounter=0;
   vector<string> lines;
   bool comment=false;
   bool lineComment=false;
   bool bracket=false;

   // ui->textBrowser->setSizePolicy();
   QString code1="hi";
   QString code2="there";
   DBTool* tool = new DBTool("TestDB");
   //Code* x = new Code(tool,file,0);
    Code* x=myCode;



       cout << "Got here 1" << endl;

       //vector<string> v;
       vector<string> v = x->parse();
       cerr<<v.size();
       ui->textBrowser->setText("");
       for(int i=0; i<v.size(); i++){//lines
           vector<string> t = x->tokenize(v[i]);
           vector<string> delims = x->delimiters(v.at(i));
           for(int a=0; a<t.size();a++){
               if(a==0){
                   std::string s = std::to_string(i);
                   if(i<10){
                       s=s+"  | ";
                   }
                   else if(i<100){
                       s=s+" | ";
                   }
                       else if(i<1000){
                       s=s+"| ";
                   }
                    ui->textBrowser->setTextColor("Orange");
                   QString temp= QString::fromStdString(s);
                   ui->textBrowser->insertPlainText(temp);
               }


               string rawHTML = (a < delims.size()) ? delims.at(a) : " ";
               QString qstr1 = QString::fromStdString(rawHTML);
               ui->textBrowser->setTextColor("Cornsilk ");
               ui->textBrowser->insertPlainText(qstr1);

               QString qstr = QString::fromStdString(t[a]);
               int type = x->categorize(t[a]);
             //  int dtype = x->categorize()
              // int delimType= x->categorize(delims[a]);
               if(a==0&&type==11)
               {
                   lineComment=true;
               }
               else if(a==0&&type!=11)
               {
                   lineComment=false;
               }

              if(type==9){
               comment=true;
              }
              if(type==10)
              {
                  comment=false;
              }
                   switch(type)
                   {
                   case 1:
                       ui->textBrowser->setTextColor("Deepskyblue");
                       break;
                   case 2:
                       ui->textBrowser->setTextColor("Plum");
                       break;
                   case 3:
                       ui->textBrowser->setTextColor("Plum");
                       break;
                   case 4:
                       ui->textBrowser->setTextColor("Salmon");
                       break;
                   case 5:
                       ui->textBrowser->setTextColor("Salmon");
                       break;
                   case 6:
                       ui->textBrowser->setTextColor("Dodgerblue");
                       break;
                   case 7:
                       ui->textBrowser->setTextColor("Plum");
                       break;
                   case 8:
                       ui->textBrowser->setTextColor("Plum");
                       break;
                   case 9:
                       ui->textBrowser->setTextColor("Lightgreen");
                       break;
                   case 10:
                       ui->textBrowser->setTextColor("Lightgreen");
                       break;
                   case 11:
                       ui->textBrowser->setTextColor("Lightgreen");
                       break;
                   case 12:
                       tabCounter++;
                       bracket=true;
                       break;
                   case 13:
                       tabCounter--;
                       break;
                   case 0:
                       ui->textBrowser->setTextColor("Cornsilk ");
                       break;
                   default:
                       ui->textBrowser->setTextColor("Cornsilk ");
                       break;
                   }

                   if(comment||lineComment)
                   {
                       ui->textBrowser->setTextColor("Lightgreen");

                   }


                   if(a==0){
                       //for(int tabs=0;tabs<tabCounter;tabCounter++){
                       if(bracket){
                           for(int tabs=0;tabs<tabCounter-1;tabs++)
                           {
                                   ui->textBrowser->insertPlainText("    ");

                           }
                           bracket=false;


                       }
                       else
                       {

                          for(int tabs=0;tabs<tabCounter;tabs++)
                          {
                                  ui->textBrowser->insertPlainText("    ");

                          }
                       }

                      // }
                   }

//                else{
//                    switch(delimType)
//                    {
//                    case 9:
//                        ui->textBrowser->setTextColor("green");
//                        break;
//                    case 0:
//                        ui->textBrowser->setTextColor("black");
//                        break;
//                    default:
//                        ui->textBrowser->setTextColor("black");
//                        break;
//                    }
//                }

                   // ui->textBrowser->moveCursor(QTextCursor::End);
                   // ui->textBrowser::moveCursor(  ui->textBrowser::End);
                   ui->textBrowser->insertPlainText(qstr);
                   //  ui->textBrowser->append(qstr);
                  // cout << "Testing" << endl;
               }
               ui->textBrowser->append("");
           }

   return x;

   }




    void textView::on_comboBox_activated(const QString &arg1)
    {
        if(arg1=="Drew")
        {
            student="Drew";
        }

    }

    void textView::on_comboBox_2_activated(const QString &arg1)
    {
        if(student=="Drew"&&arg1=="Student")
        {

            DBTool* tool = new DBTool("TestDB");
            Code* x = new Code(tool,"/Users/drewcarleton/Project205/axolotl/GUI/BinaryTree.java",0);

            myCode=this->updateCode(x);


          //  ui->textBrowser->cursor().pos()

            //int para= ui->textBrowser->paragraphAt(QCursor::pos());     // te is the textEdit object
           //  QString line=ui->textBrowser->text(para);
            // cerr<<line;
        }

    }





void textView::on_pushButton_clicked()
{
    //Code* temp =this->updateCode("/Users/drewcarleton/Project205/axolotl/GUI/BinaryTree.java");
    this->makeComment(myCode);

}

void textView::on_lineEdit_2_textChanged(const QString &arg1)
{
    commentLoc=arg1.toInt();
}
