#ifndef _GAME_RENDER_MWSCENE_H
#define _GAME_RENDER_MWSCENE_H

#include <utility>
#include <openengine/ogre/renderer.hpp>

namespace Ogre
{
    class Camera;
    class Viewport;
    class SceneManager;
    class SceneNode;
    class RaySceneQuery;
}

namespace MWRender
{
  /** Class responsible for Morrowind-specific interfaces to OGRE.

      This might be refactored partially into a non-mw specific
      counterpart in ogre/ at some point.
   */
  class MWScene
  {
    OEngine::Render::OgreRenderer &rend;

    // Root node for all objects added to the scene. This is rotated so
    // that the OGRE coordinate system matches that used internally in
    // Morrowind.
    Ogre::SceneNode *mwRoot;
    Ogre::RaySceneQuery *mRaySceneQuery;

  public:
    MWScene(OEngine::Render::OgreRenderer &_rend);

    Ogre::Camera *getCamera() { return rend.getCamera(); }
    Ogre::SceneNode *getRoot() { return mwRoot; }
    Ogre::SceneManager *getMgr() { return rend.getScene(); }
    Ogre::Viewport *getViewport() { return rend.getViewport(); }
    Ogre::RaySceneQuery *getRaySceneQuery() { return mRaySceneQuery; }

    //gets the handle of the object the player is looking at
    //pair<name, distance>
    //name is empty and distance = -1 if there is no object which
    //can be faced
    std::pair<std::string, float> getFacedHandle();
  };
}

#endif
