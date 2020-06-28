//
// Created by Matthew Olson on 6/17/20.
//

#ifndef BATTLETOWERMANAGER_MOVEFACTORY_H
#define BATTLETOWERMANAGER_MOVEFACTORY_H

#include <map>
#include "src/IMove.h"

class IMove;
class MoveFactory {
public:
    static MoveFactory *getFactory() {
        if (_factory != nullptr) { return _factory; }
        else {
            _factory = new MoveFactory();
            return _factory;
        }
    }
    IMove *getMove(const std::string& move);
    IMove *makeMove(const std::string& move);
    ~MoveFactory();
private:
    static MoveFactory *_factory;
    MoveFactory();
    std::map<std::string, IMove *> moves;
};


#endif //BATTLETOWERMANAGER_MOVEFACTORY_H
