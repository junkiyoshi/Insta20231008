#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	float span = 1;
	ofColor color;
	for (float x_start = 18; x_start < 720; x_start += 144)
	{
		for (float x = x_start; x < x_start + 108; x += span) {

			for (float y = 60; y < 660; y += span) {

				float noise_value = ofMap(ofNoise(x * 0.015, y * 0.003 + ofGetFrameNum() * 0.02, ofGetFrameNum() * 0.01), 0, 1, 0, 10);
				if ((int)noise_value % 2 == 0) {

					continue;
				}

				this->mesh.addVertex(glm::vec3(x, y, 0));
				this->mesh.addVertex(glm::vec3(x + span, y, 0));
				this->mesh.addVertex(glm::vec3(x + span, y + span, 0));
				this->mesh.addVertex(glm::vec3(x, y + span, 0));

				this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 4); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
				this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);

				color.setHsb(ofMap(x_start, 18, 720, 0, 255), 180, 255);
				for (int i = 0; i < 4; i++) {

					this->mesh.addColor(color);
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->mesh.draw();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}