using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tile : MonoBehaviour 
{
    public int fila = -1;
    public int columna = -1;
    
    public bool walkable = true;
    public bool current = false;
    public bool target = false;
    public bool selectable = false;
    public bool objective = false;

    public List<Tile> adjacencyList = new List<Tile>();
    public List<Tile> vecinos = new List<Tile>();
    public Stack<Tile> padres = new Stack<Tile>();

    //Needed BFS (breadth first search)
    public bool visited = false;
    public Tile parent = null;
    public int distance = 0;

    //For A*
    public float f = 0;
    public float g = 0;
    public float h = 0;

	// Use this for initialization
	void Start () 
	{

    }   
	
	// Update is called once per frame
	void Update () 
	{
        if (current)
        {
            GetComponent<Renderer>().material.color = Color.magenta;
        }
        else if (target)
        {
            GetComponent<Renderer>().material.color = Color.green;
        }
        else if (selectable)
        {
            GetComponent<Renderer>().material.color = Color.red;
        }
        else if (objective)
        {
            GetComponent<Renderer>().material.color = Color.blue;
        }
        else
        {
            GetComponent<Renderer>().material.color = Color.white;
        }
	}

    public void Reset()
    {
        adjacencyList.Clear();
        vecinos.Clear();

        current = false;
        target = false;
        selectable = false;
        objective = false;

        visited = false;
        parent = null;
        distance = 0;

        f = 0;
        g = 0;
        h = 0;
    }

    public void FindNeighbors(float jumpHeight, Tile target)
    {
        Reset();

        /*CheckTile(Vector3.forward, jumpHeight, target);
        CheckTile(-Vector3.forward, jumpHeight, target);
        CheckTile(Vector3.right, jumpHeight, target);
        CheckTile(-Vector3.right, jumpHeight, target);
        */

        if ((fila - 1) >= 0)
        {
            GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
            Tile tile = generateGrid[0].GetComponent<GenerateGrid>().grid[fila - 1, columna].GetComponent<Tile>();
            tile.parent = this;
            tile.padres = new Stack<Tile>(new Stack<Tile>(this.padres));
            tile.padres.Push(this);
            //Debug.Log("TILE (" + tile.fila + ", " + tile.columna + ") " + showStack(tile.padres) + "|| COUNT: "+ tile.padres.Count);
            //tile.f = this.f + 1;
            //Debug.Log("Choosen Tile " + tile.fila + ", "+ tile.columna);
            vecinos.Add(tile);
        }
        //Debug.Log("Below Tile " + vecinos[0].fila + ", " + vecinos[0].columna);
        if ((fila + 1) <= 8)
        {
            GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
            Tile tile = generateGrid[0].GetComponent<GenerateGrid>().grid[fila + 1, columna].GetComponent<Tile>();
            tile.parent = this;
            tile.padres = new Stack<Tile>(new Stack<Tile>(this.padres));
            tile.padres.Push(this);
            //Debug.Log("TILE (" + tile.fila + ", " + tile.columna + ") " + showStack(tile.padres) + "|| COUNT: "+ tile.padres.Count);
            //tile.f = this.f + 1;
            //Debug.Log("Choosen Tile " + tile.fila + ", "+ tile.columna);
            vecinos.Add(tile);
        }
        //Debug.Log("Above Tile " + vecinos[1].fila + ", " + vecinos[1].columna);
        if ((columna - 1) >= 0)
        {
            GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
            Tile tile = generateGrid[0].GetComponent<GenerateGrid>().grid[fila, columna - 1].GetComponent<Tile>();
            tile.parent = this;
            tile.padres = new Stack<Tile>(new Stack<Tile>(this.padres));
            tile.padres.Push(this);
            //Debug.Log("TILE (" + tile.fila + ", " + tile.columna + ") " + showStack(tile.padres) + "|| COUNT: "+ tile.padres.Count);
            //tile.f = this.f + 1;
            //Debug.Log("Choosen Tile " + tile.fila + ", "+ tile.columna);
            vecinos.Add(tile);
        }
        //Debug.Log("Right Tile " + vecinos[2].fila + ", " + vecinos[2].columna);
        if ((columna + 1) <= 8)
        {
            GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
            Tile tile = generateGrid[0].GetComponent<GenerateGrid>().grid[fila, columna + 1].GetComponent<Tile>();
            tile.parent = this;
            tile.padres = new Stack<Tile>(new Stack<Tile>(this.padres));
            tile.padres.Push(this);
            //Debug.Log("TILE (" + tile.fila + ", " + tile.columna + ") " + showStack(tile.padres) + "|| COUNT: "+ tile.padres.Count);
            //tile.f = this.f + 1;
            //Debug.Log("Choosen Tile " + tile.fila + ", "+ tile.columna);
            vecinos.Add(tile);
        }
        //Debug.Log("Left Tile " + vecinos[3].fila + ", " + vecinos[3].columna);

    }

    public void CheckTile(Vector3 direction, float jumpHeight, Tile target)
    {
        Vector3 halfExtents = new Vector3(0.25f, (1 + jumpHeight) / 2.0f, 0.25f);
        Collider[] colliders = Physics.OverlapBox(transform.position + direction, halfExtents);

        foreach (Collider item in colliders)
        {
            Tile tile = item.GetComponent<Tile>();
            if (tile != null && tile.walkable)
            {
                RaycastHit hit;

                if (!Physics.Raycast(tile.transform.position, Vector3.up, out hit, 1) || (tile == target))
                {
                    adjacencyList.Add(tile);
                }
            }
        }
    }

    public string showStack(Stack<Tile> stack)
    {
        Stack<Tile> tempStack = new Stack<Tile>(new Stack<Tile>(stack));
        string mensaje = "";
        while(tempStack.Count > 0)
        {
            Tile tile = tempStack.Pop();
            mensaje += "(" + tile.fila + ", " + tile.columna + "),";
        }
        return mensaje;
    }
}
