using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ActionManager : MonoBehaviour
{

    static TacticsMove actual;
    static bool wait = false;
    static bool attack = false;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public static void SetActual(TacticsMove newActual)
    {
        actual = newActual;
        //Debug.Log(actual);
    }

    public static void Wait()
    {
        wait = true;
    }

    public static void Attack()
    {
        attack = true;
    }

    public static bool GetAttack()
    {
        return attack;
    }

    public static void InflictDamage(GameObject attackerObject, GameObject defenderObject)
    {
        PlayerStats attacker = null;
        NPCStats defender = null;

        Debug.Log(attackerObject.tag);
        if (attackerObject.tag == "Player")
        {
            attacker = attackerObject.GetComponent<PlayerStats>();
        }
        else
        {
            Debug.Log("NO SE HA ENCONTRADO ATACANTE");
        }

        Debug.Log(defenderObject.tag);
        if (defenderObject.tag == "NPC")
        {
            defender = defenderObject.GetComponent<NPCStats>();
        }
        else
        {
            Debug.Log("NO SE HA ENCONTRADO DEFENSOR");
        }

        defender.health -= attacker.attack;
        attack = false;
        wait = true;
    }

    public static bool EndOfAction()
    {
        if (wait)
        {
            TurnManager.EndTurn(actual);
            wait = false;
            actual = null;
            GameObject[] tiles = GameObject.FindGameObjectsWithTag("Tile");
            foreach(GameObject t in tiles)
            {
                t.GetComponent<Tile>().objective = false;
            }
            return true;
        }
        
        if (attack)
        {
            actual.GetCurrentTile();
            actual.currentTile.FindNeighbors(0, actual.currentTile);
            foreach(Tile t in actual.currentTile.vecinos)
            {
                if (!t.walkable)
                {
                    t.objective = true;
                }
            }
        }

        return false;
    }
}
