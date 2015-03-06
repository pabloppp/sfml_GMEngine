#include "BoxCollider.hpp"

#include "../Game.hpp"
#include "CircleCollider.hpp"

#include <math.h>

#define PI  3.14159265 

using namespace gme;

void BoxCollider::setup(){
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);
    rectangle.setPointCount(4);
    if(size.x == 0 || size.y == 0)  setSize(60, 60);
    debugColor = sf::Color::Yellow;
}

void BoxCollider::update(){
    checked = false;
    if(!colliding){
        debugColor = sf::Color::Yellow;
    }
    colliding = false;
}

void BoxCollider::setSize(Vector2 s){
    size = s;
    outerRadius = sqrt((size.x/2)*(size.x/2) + (size.y/2)*(size.y/2));
    innerRadius = fmin(size.x, size.y)/2.0;
    //rectangle.setOrigin(s.x/2, s.y/2);
}

void BoxCollider::setSize(float x, float y){
    setSize(Vector2(x, y));
}

void BoxCollider::checkCollision(Collider* col){
    if(checkTags(col) || col->checkTags(this)) return;
    if(dynamic_cast<BoxCollider*>(col)){
        Vector2 cA = getGlobalCenter();   
        Vector2 cB = col->getGlobalCenter();
        
        float maxR = outerRadius;
        float minR = innerRadius;

        float colMaxR = ((BoxCollider*)col)->outerRadius;
        float colMinR = ((BoxCollider*)col)->innerRadius;
        
        Vector2 AB(cB.x-cA.x, cB.y-cA.y);
        
        float d2 = AB.magnitude2();
        float rMax2 = (maxR+colMaxR)*(maxR+colMaxR);
        
        if(d2 > rMax2) {
            return;
        }
        float rMin2 = (minR+colMinR)*(minR+colMinR); 
        if(d2 < rMin2){
            noticeCollision(col);
            col->noticeCollision(this);
            return;
        }
        else{
            std::vector<Vector2> points = getRotatedPoints();
            std::vector<Vector2> opoints = ((BoxCollider*)col)->getRotatedPoints();
            
            for(int i=0;i<4;i++){
                Vector2 m = opoints[i];
                Vector2 a = points[0];
                Vector2 b = points[1];
                Vector2 d = points[3];
                if(checkPointIn(opoints[i],points[0],points[1],points[3])
                || checkPointIn(points[i],opoints[0],opoints[1],opoints[3])) {
                    noticeCollision(col);
                    col->noticeCollision(this);
                    return; 
                }
                
            }
            for(int i=0;i<4;i++){
                int nexti = (i+1) % 4;
                
                Vector2 p1 = points[i];
                Vector2 q1 = points[nexti];
                
                for(int j=0;j<4;j++){
                    int nextj = (j+1) % 4;
                    
                    Vector2 p2 = opoints[j];
                    Vector2 q2 = opoints[nextj];
                    
                    int o1 = orientation(p1, q1, p2);
                    int o2 = orientation(p1, q1, q2);
                    int o3 = orientation(p2, q2, p1);
                    int o4 = orientation(p2, q2, q1);
                    
                    if(o1 != o2 && o3 != o4){
                        noticeCollision(col);
                        col->noticeCollision(this);
                        return;
                    }
                }
    
            }
        
        }
        
    }
    else if(dynamic_cast<CircleCollider*>(col)){
        
    }
}

bool BoxCollider::checkPointIn(Vector2 m, Vector2 a, Vector2 b, Vector2 d) {
    Vector2 am = Vector2(m.x-a.x, m.y-a.y);
    Vector2 ab = Vector2(b.x-a.x, b.y-a.y);
    Vector2 ad = Vector2(d.x-a.x, d.y-a.y);
    float amab = am.x*ab.x + am.y*ab.y;
    float amad = am.x*ad.x + am.y*ad.y;
    float abab = ab.x*ab.x + ab.y*ab.y;
    float adad = ad.x*ad.x + ad.y*ad.y;

    if(amab > 0 && amab < abab && amad > 0 && amad < adad){
        return true;
    }
    return false;
}

int BoxCollider::orientation(Vector2 p, Vector2 q, Vector2 r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;
    return (val > 0)? 1: 2;
}



void BoxCollider::render(){
    std::vector<Vector2> points = getRotatedPoints();
 
    rectangle.setPoint(0, sf::Vector2f(points.at(0).x, points.at(0).y));
    rectangle.setPoint(1, sf::Vector2f(points.at(1).x, points.at(1).y));
    rectangle.setPoint(2, sf::Vector2f(points.at(2).x, points.at(2).y));
    rectangle.setPoint(3, sf::Vector2f(points.at(3).x, points.at(3).y));
    rectangle.setOutlineColor(debugColor); 
    
    /*sf::CircleShape cs;
    cs.setRadius(outerRadius);
    cs.setPosition(getGlobalCenter().x, getGlobalCenter().y);
    cs.setFillColor(sf::Color::Transparent);
    cs.setOutlineThickness(1);
    cs.setOutlineColor(sf::Color::Magenta);
    cs.setOrigin(outerRadius, outerRadius);
    Game::getWindow()->draw(cs);*/
    Game::getWindow()->draw(rectangle);
}

Vector2 BoxCollider::getSize(){
    return size;
}

std::vector<Vector2> BoxCollider::getRotatedPoints() {
    
    std::vector<Vector2> rotatedPoints;
    Vector2 cA = getGlobalCenter(); 
    Vector2 p1(cA.x-size.x/2, cA.y-size.y/2);
    Vector2 p2(cA.x+size.x/2, cA.y-size.y/2);
    Vector2 p3(cA.x+size.x/2, cA.y+size.y/2);
    Vector2 p4(cA.x-size.x/2, cA.y+size.y/2);
    if(canRotate){

        float rot = gameObject()->getTransform()->getRotation();
        rot = rot * (PI/180); 
        float x = -size.x/2;
        float y = -size.y/2;

        p1 = Vector2(cA.x + (x * cos(rot)) - (y * sin(rot)) , cA.y + (x * sin(rot)) + (y * cos(rot)));
        p2 = Vector2(cA.x + (-x * cos(rot)) - (y * sin(rot)) , cA.y + (-x * sin(rot)) + (y * cos(rot)));
        p3 = Vector2(cA.x + (-x * cos(rot)) - (-y * sin(rot)) , cA.y + (-x * sin(rot)) + (-y * cos(rot)));
        p4 = Vector2(cA.x + (x * cos(rot)) - (-y * sin(rot)) , cA.y + (x * sin(rot)) + (-y * cos(rot)));
    }
    
    rotatedPoints.push_back(p1);
    rotatedPoints.push_back(p2);
    rotatedPoints.push_back(p3);
    rotatedPoints.push_back(p4);
    
    return rotatedPoints;
}




