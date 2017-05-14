#include "Family.h"

Family::Family() {

}

Family::~Family() {
	items.clear();
}

Family::Family(int id, const char * name) {
	this->id = id;
	strcpy(this->name, name);
}

void Family::addItem(int itemId) {
	items.push_back(itemId);
}

void Family::printName() {
	fprintf(stderr, "%i - %s\n", id, name);
}