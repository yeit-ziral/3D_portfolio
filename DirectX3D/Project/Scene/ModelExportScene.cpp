#include "Framework.h"
#include "ModelExportScene.h"

ModelExportScene::ModelExportScene()
{
	string name = "Knight D Pelegrini";

	exporter = new ModelExporter(name);
	modelAnimator = new ModelAnimator(name);

	//exporter->ExportModel();
	//
	exporter->ExportClip("Idle");
	exporter->ExportClip("Pushing");
	exporter->ExportClip("Death");

	modelAnimator->ReadClip("Idle");
	modelAnimator->ReadClip("Pushing");
	modelAnimator->ReadClip("Death");
	
	//reader = new ModelReader(name);
	//
	//reader->SetShader(L"02ModelAnimation");


	//bodyparts.resize(reader->GetMeshes().size());
	//
	//for (UINT i = 0; i < reader->GetMeshes().size(); i++)
	//{
	//	bodyparts[i] = new BodyPart(reader->GetMaterials(), reader->GetMeshes()[i]);
	//}


	//model = new ModelA(name);

	//model = new Model(name);
	////model->scale *= 30.0f;
	//model->scale *= 0.1;

	//groot = new Groot();
	//pumpkin = new Ghost();
}

ModelExportScene::~ModelExportScene()
{
	delete exporter;
	//delete model;

	//delete groot;
	delete modelAnimator;
}

void ModelExportScene::Update()
{
	//for (BodyPart* part : bodyparts)
	//{
	//	part->Update();
	//}

	//model->Update();

	modelAnimator->Update();

	//groot->Update();

	//pumpkin->Update();
}

void ModelExportScene::PreRender()
{
}

void ModelExportScene::Render()
{
	//for (int i = 0; i < reader->GetMeshes().size(); i++)
	//{
	//	bodyparts[i]->Render(i);
	//}

	//model->Render();

	modelAnimator->Render();

	//groot->Render();

	//pumpkin->Render();
}

void ModelExportScene::PostRender()
{
	//model->GetReader()->Debug();
	//model->Debug();

	modelAnimator->GetReader()->Debug();
	modelAnimator->Debug();

	//groot->Debug();

	//pumpkin->Debug();
}
