#include "Water.h"

Water::Water(CCTexture2D particleTexture){
	winSize = CCDirector::sharedDirector()->getWinSize();
	ParticleTexture = particleTexture;
	for(int i =0; i < 201; i++){
		columns[i] = new WaterColumn;
		columns[i]->Height = 240;
		columns[i]->TargetHeight = 240;
		columns[i]->Speed = 0;
	}
}

float Water::GetHeight(float x){
	if(x < 0 || x > 800){
		return 240;
	}
	return columns[(int)(x/Scale(800))]->Height;
}

void Water::UpdateParticle(Particle *particle){
	const float Gravity = 0.3f;
	particle->Velocity.Y += Gravity;
	particle->Position += particle->Velocity;
	particle->Orientation = GetAngle(particle->Velocity);
}

void Water::Update(){
	for(int i =0; i < 201; i++){
		columns[i]->Update(Dampening,Tension);
	}
	float lDeltas[201];
	float rDeltas[201];

	for(int j=0; j<8;j++){
		for(int i=0; i < 201;i++){
			if(i > 0){
				lDeltas[i] = Spread * (columns[i]->Height - columns[i - 1]->Height);
				columns[i - 1]->Speed += lDeltas[i];
			}
			if(i < 201 -1){
				rDeltas[i] = Spread * (columns[i]->Height - columns[i + 1]->Height);
				columns[i + 1]->Speed += rDeltas[i];
			}
		}
		for(int i = 0; i < 201; i++){
			if(i > 0){
				columns[i - 1]->Height += lDeltas[i];
			}
			if(i < 201 - 1){
				columns[i + 1]->Height += rDeltas[i];
			}
		}
	}
	for each (Particle p in particles){
		UpdateParticle(&p);
	}
	//particles = particles.Where(x => x.Position.X >= 0 && x.Position.X <= 800 && x.Position.Y - 5 <= GetHeight(x.Position.X)).ToList();
}

void Water::DrawToRenderTargets(){
	for each (Particle p in particles){
		Vector2 *origin = new Vector2(ParticleTexture.getContentSize().width,ParticleTexture.getContentSize().height);
		spriteBatch.initWithTexture(&ParticleTexture,256);
		spriteBatch.setPosition(p.Position.X,p.Position.Y);
		spriteBatch.setRotation(p.Orientation);
		spriteBatch.draw();
	}

	const float thickness = 20;
	float scale = Scale(1);
	for(int i = 0; i < 201; i++){
		CCPoint *p1 = new CCPoint((i-1) * scale,columns[i - 1]->Height);
		CCPoint *p2 = new CCPoint(i * scale, columns[i]->Height);
		CCPoint *p3 = new CCPoint(p1->x,p1->y - thickness);
		CCPoint *p4 = new CCPoint(p2->x,p2->y - thickness);
		//ccDrawPoly(
	}
	//ccDrawPoly
}

void Water::Draw(){
	
}
