#include "Quest.h"

Quest::Quest() {

}

Quest::~Quest() {
	giveFamilly.clear();
	requireItemId.clear();
}

Quest::Quest(int id, bool bombe, bool bombeUp, bool life, bool light, int disguise, int key, int giveOption, int giveMode, int removeFamilly, int famillyId, const char * titre, const char * description) {
	strcpy(this->titre, titre);
	strcpy(this->description, description);
	this->id = id;
	this->giveOption = giveOption;
	this->giveOption = giveMode;
	this->giveOption = removeFamilly;
	giveFamilly.push_back(famillyId);
}
Quest::Quest(int id, bool bombe, bool bombeUp, bool life, bool light, int disguise, int key, int giveOption, int giveMode, int removeFamilly, const char * titre, const char * description) {
	strcpy(this->titre, titre);
	strcpy(this->description, description);
	this->id = id;
	this->giveOption = giveOption;
	this->giveOption = giveMode;
	this->giveOption = removeFamilly;
}

char * Quest::getDescription() {
	return description;
}

int Quest::getGiveOption() {
	return giveOption;
}

int Quest::getGiveMode() {
	return giveMode;
}

int Quest::getRemoveFamilly() {
	return removeFamilly;
}

std::vector<int> Quest::getGiveFamilly() {
	return giveFamilly;
}

std::map<int, int> Quest::getRequireItemId() {
	return requireItemId;
}

void Quest::addRequireItemId(int itemId, int quantity) {
	requireItemId[itemId] = quantity;
}

void Quest::addGiveFamilly(int famillyId) {
	giveFamilly.push_back(famillyId);
}

void Quest::printName() {
	fprintf(stderr, "%i - %s - %s\n", id, titre, description);
}