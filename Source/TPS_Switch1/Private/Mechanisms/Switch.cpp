// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanisms/Switch.h"

void ASwitch::OnHit(UMaterialInterface* color)
{
	IsOn = true;
	Mesh->SetMaterial(0, color);
}