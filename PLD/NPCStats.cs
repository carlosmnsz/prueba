using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NPCStats : NPCMove
{
    public int health = 10;

    protected override void Update()
    {
        if(health <= 0)
        {
            TurnManager.enemigos.Remove(this);
            Destroy(gameObject);
        }
        base.Update();
    }
}
