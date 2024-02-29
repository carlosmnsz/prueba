using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using TMPro;
using UnityEngine.UI;

public class TurnManager : MonoBehaviour 
{
    static Dictionary<string, List<TacticsMove>> units = new Dictionary<string, List<TacticsMove>>();
    //static Queue<string> turnKey = new Queue<string>();
    //static Queue<TacticsMove> turnTeam = new Queue<TacticsMove>();
    static List<TacticsMove> jugadores = new List<TacticsMove>();
    static List<TacticsMove> enemigos = new List<TacticsMove>();
    static public List<TacticsMove> currentGroup = new List<TacticsMove>();
    static public bool turnoJugador = false;
    static bool pass = true;
    static bool occupied = false;

    // Use this for initialization
    void Start () 
	{
        
    }

    /*
	// Update is called once per frame
	void Update () 
	{
        if (turnTeam.Count == 0)
        {
            InitTeamTurnQueue();
        }
	}

    static void InitTeamTurnQueue()
    {
        List<TacticsMove> teamList = units[turnKey.Peek()];

        foreach (TacticsMove unit in teamList)
        {
            turnTeam.Enqueue(unit);
        }

        StartTurn();
    }

    public static void StartTurn()
    {
        if (turnTeam.Count > 0)
        {
            turnTeam.Peek().BeginTurn();
        }
    }

    public static void EndTurn()
    {
        TacticsMove unit = turnTeam.Dequeue();
        unit.EndTurn();

        if (turnTeam.Count > 0)
        {
            StartTurn();
        }
        else
        {
            string team = turnKey.Dequeue();
            turnKey.Enqueue(team);
            InitTeamTurnQueue();
        }
    }

    public static void AddUnit(TacticsMove unit)
    {
        List<TacticsMove> list;

        if (!units.ContainsKey(unit.tag))
        {
            list = new List<TacticsMove>();
            units[unit.tag] = list;

            if (!turnKey.Contains(unit.tag))
            {
                turnKey.Enqueue(unit.tag);
            }
        }
        else
        {
            list = units[unit.tag];
        }

        list.Add(unit);
    }
    */

    void Update()
    {
        if (pass)
        {
            pass = false;
            currentGroup.Clear();
            if (turnoJugador)
            {
                currentGroup = new List<TacticsMove>(jugadores);
            }
            else
            {
                currentGroup = new List<TacticsMove>(enemigos);
                StartTurn();
            }
            
        }
    }

    public static void StartTurn()
    {
        if(currentGroup.Count > 0)
        {
            currentGroup[0].BeginTurn();
        }
    }

    public static void EndTurn(TacticsMove objeto)
    {
        if (objeto.tag == "Player")
        {
            TacticsMove unit = currentGroup.Find(x => x==objeto);
            unit.EndTurn();
            currentGroup.Remove(objeto);
            //Debug.Log("FIN TURNO: " + unit.identificador + " || CURRENTGROUP: " + currentGroup.Count);
        }
        else
        { 
            TacticsMove unit = currentGroup[0];
            unit.EndTurn();
            currentGroup.RemoveAt(0);

            if (currentGroup.Count > 0)
            {
                StartTurn();
            }
            else
            {
                //Debug.Log("FIN TURNO NPC");
                PassTurn();
            }
        }
    }

    public static void AddUnit(TacticsMove unit)
    {
        
        if(unit.tag == "Player")
        {
            jugadores.Add(unit);
        }
        else if(unit.tag == "NPC")
        {
            enemigos.Add(unit);
        }
    }

    public static void PassTurn()
    {
        if (turnoJugador)
        {
            foreach (TacticsMove t in jugadores)
            {
                t.GetComponent<Renderer>().material.color = Color.blue;
            }
        }
        else
        {
            foreach (TacticsMove t in enemigos)
            {
                t.GetComponent<Renderer>().material.color = Color.green;
            }
        }
        turnoJugador = !turnoJugador;
        pass = true;
        //Debug.Log("SE PASA EL TURNO");
    }

    public static void SetOccupied(bool newOccupied)
    {
        occupied = newOccupied;
    }

    public static bool GetOccupied()
    {
        return occupied;
    }
}
