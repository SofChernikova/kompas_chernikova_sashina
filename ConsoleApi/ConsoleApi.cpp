// ConsoleApi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#import "D:\kompas\Bin\kAPI5.tlb"
#import "D:\kompas\Bin\ksConstants3D.tlb"


using namespace Kompas6API5;
using namespace Kompas6Constants3D;


void AnastasiaSashina(Kompas6API5::KompasObjectPtr kompas) {
    Kompas6API5::ksDocument3DPtr doc;
    doc = kompas->Document3D();
    doc->Create(false, true);
    doc = kompas->ActiveDocument3D();



    kompas->Visible = true;

    ksPartPtr Part;
    Part = doc->GetPart(Kompas6Constants3D::pTop_Part);
    
    ksEntityPtr sketch = Part->NewEntity(o3d_sketch);
    ksSketchDefinitionPtr sketchDef = sketch->GetDefinition();
    sketchDef->SetPlane(Part->GetDefaultEntity(o3d_planeXOY));
    sketch->Create();
    ksDocument2DPtr doc2D = sketchDef->BeginEdit();

    doc2D->ksLineSeg(0, 0, 0, 30, 1);
    doc2D->ksLineSeg(0, 30, 30, 30, 1);
    doc2D->ksLineSeg(30, 30, 30, 100, 1);
    doc2D->ksLineSeg(30, 100, 70, 100, 1);
    doc2D->ksLineSeg(70, 100, 70, 30, 1);
    doc2D->ksLineSeg(70, 30, 110, 30, 1);
    doc2D->ksLineSeg(110, 30, 110, 100, 1);
    doc2D->ksLineSeg(110, 100, 150, 100, 1);
    doc2D->ksLineSeg(150, 100, 150, 30, 1);
    doc2D->ksLineSeg(150, 30, 180, 30, 1);
    doc2D->ksLineSeg(180, 30, 180, 0, 1);
    doc2D->ksLineSeg(180, 0, 0, 0, 1);


    doc2D->ksCircle(15, 15, 7, 1);
    doc2D->ksCircle(165, 15, 7, 1);    

    sketchDef->EndEdit();

    ksEntityPtr extr = Part->NewEntity(o3d_bossExtrusion);
    ksBossExtrusionDefinitionPtr extrDef = extr->GetDefinition();
    extrDef->SetSideParam(TRUE, etBlind, 10, 0, FALSE);
    extrDef->directionType* (Kompas6Constants3D::dtNormal);
    extrDef->SetSketch(sketch);
    extr->Create();

    doc->SaveAs(L"D:\\kompas\\details\\a_sashina.m3d"); 

}

void SofiaChernikova(Kompas6API5::KompasObjectPtr kompas) {
    Kompas6API5::ksDocument3DPtr doc;
    doc = kompas->Document3D();
    doc->Create(false, true);
    doc = kompas->ActiveDocument3D();

    kompas->Visible = true;

    ksPartPtr Part;
    Part = doc->GetPart(Kompas6Constants3D::pTop_Part);

    ksEntityPtr sketch = Part->NewEntity(o3d_sketch);
    ksSketchDefinitionPtr sketchDef = sketch->GetDefinition();
    sketchDef->SetPlane(Part->GetDefaultEntity(o3d_planeXOZ));
    sketch->Create();
    ksDocument2DPtr doc2D = sketchDef->BeginEdit();

    doc2D->ksLineSeg(0, 0, 0, 70, 1);
    doc2D->ksLineSeg(0, 70, 30, 70, 1);
    doc2D->ksLineSeg(30, 70, 30, 120, 1);
    doc2D->ksLineSeg(30, 120, 70, 120, 1);
    doc2D->ksLineSeg(70, 120, 70, 70, 1);
    doc2D->ksLineSeg(70, 70, 110, 70, 1);
    doc2D->ksLineSeg(110, 70, 110, 120, 1);
    doc2D->ksLineSeg(110, 120, 150, 120, 1);
    doc2D->ksLineSeg(150, 120, 150, 70, 1);
    doc2D->ksLineSeg(150, 70, 180, 70, 1);
    doc2D->ksLineSeg(180, 70, 180, 0, 1);
    doc2D->ksLineSeg(180, 0, 150, 0, 1);
    doc2D->ksLineSeg(30, 0, 0, 0, 1);

    doc2D->ksArcBy3Points(30, 0, 60, 35, 150, 0, 1);
    doc2D->ksCircle(50, 110, 7, 1);
    doc2D->ksCircle(130, 110, 7, 1);


    sketchDef->EndEdit();

    ksEntityPtr extr = Part->NewEntity(o3d_bossExtrusion);
    ksBossExtrusionDefinitionPtr extrDef = extr->GetDefinition();
    extrDef->SetSideParam(TRUE, etBlind, 10, 0, FALSE);
    extrDef->directionType* (Kompas6Constants3D::dtNormal);
    extrDef->SetSketch(sketch);
    extr->Create();


    doc->SaveAs(L"D:\\kompas\\details\\s_chernikova.m3d");

}

int main()
{
    CoInitialize(NULL);
    Kompas6API5::KompasObjectPtr kompas;
    HRESULT hRes;
    hRes = kompas.GetActiveObject(L"Kompas.Application.5");
    if (FAILED(hRes)) {
        kompas.CreateInstance(L"Kompas.Application.5");
    }

    AnastasiaSashina(kompas);
    //SofiaChernikova(kompas);
    CoUninitialize();

}

