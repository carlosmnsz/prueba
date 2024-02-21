using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TacticsMove : MonoBehaviour 
{
    public bool turn = false;

    List<Tile> selectableTiles = new List<Tile>();
    GameObject[] tiles;

    Stack<Tile> path = new Stack<Tile>();
    Tile currentTile;

    public bool moving = false;
    public int move = 4;
    public float jumpHeight = 2;
    public float moveSpeed = 2;
    public float jumpVelocity = 4.5f;

    Vector3 velocity = new Vector3();
    Vector3 heading = new Vector3();

    float halfHeight = 0;

    bool fallingDown = false;
    bool jumpingUp = false;
    bool movingEdge = false;
    Vector3 jumpTarget;

    public Tile actualTargetTile;

    //**********************
    GameObject[] casillas;

    public void encontrarCasillasSeleccionables()
    {
        GetCurrentTile();

        List<Tile> seleccionablesAbiertos = new List<Tile>();
        List<Tile> seleccionablesCerrados = new List<Tile>();
        seleccionablesCerrados.Add(currentTile);

        currentTile.FindNeighbors(0, currentTile);
        foreach(Tile t in currentTile.vecinos)
        {
            if (t.walkable)
            {
                seleccionablesAbiertos.Add(t);
            }
        }

        for(int i = 1; i < move; i++)
        {
            List<Tile> aux = new List<Tile>();
            foreach(Tile abierta in seleccionablesAbiertos)
            {
                abierta.FindNeighbors(0, abierta);

                if (abierta != currentTile)
                {
                    seleccionablesCerrados.Add(abierta);
                }

                foreach(Tile vecino in abierta.vecinos)
                {
                    if (!aux.Contains(vecino) && vecino.walkable)
                    {
                        aux.Add(vecino);
                    }
                }
            }

            seleccionablesAbiertos = aux;
        }


        casillas = GameObject.FindGameObjectsWithTag("Tile"); ;
        foreach (GameObject tile in casillas)
        {
            Tile t = tile.GetComponent<Tile>();
            /*int desplazamiento = Mathf.Abs(t.fila - currentTile.fila) + Mathf.Abs(t.columna - currentTile.columna);
            if(desplazamiento <= move && t.walkable)
            {
                t.selectable = true;
            }*/
            if (seleccionablesCerrados.Contains(t))
            {
                t.selectable = true;
            }
        }

    }

    public void encontrarCamino(Tile target)
    {
        GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
        List<Tile> abiertos = new List<Tile>();
        GetCurrentTile();

        currentTile.parent = null;
        currentTile.padres = new Stack<Tile>();
        currentTile.h = Mathf.Abs(target.fila - currentTile.fila) + Mathf.Abs(target.columna - currentTile.columna);
        currentTile.f = currentTile.h;
        abiertos.Add(currentTile);

        List<Tile> cerrados = new List<Tile>();

        while (abiertos.Count > 0)
        {
            
            Tile q = FindLowestF(abiertos);

            q.FindNeighbors(0, q);

            cerrados.Add(q);

            foreach (Tile tile in q.vecinos)
            {
                
                if(tile == target)
                {
                    //actualTargetTile = FindEndTile(tile);
                    //actualTargetTile = encontrarCasillaFinal(tile);
                    //moverHaciaCasilla(actualTargetTile);
                    moverHaciaCasilla(target);
                    return;
                }

                if (abiertos.Contains(tile))
                {
                    float tempG = q.g + 1;

                    if (tempG < tile.g)
                    {
                        tile.parent = q;
                        //tile.padres.Clear();
                        tile.padres = new Stack<Tile>(new Stack<Tile>(q.padres));
                        //Debug.Log("ANTES: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);
                        tile.padres.Push(q);
                        //Debug.Log("DESPS: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);

                        tile.g = tempG;
                        tile.f = tile.g + tile.h;
                    }
                }
                else if (cerrados.Contains(tile))
                {
                    // NADA
                }
                else
                {
                    tile.parent = q;
                    //tile.padres.Clear();
                    tile.padres = new Stack<Tile>(new Stack<Tile>(q.padres));
                    //Debug.Log("ANTES: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);
                    tile.padres.Push(q);
                    //Debug.Log("DESPS: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);

                    tile.g = q.g + 1;
                    tile.h = Mathf.Abs(target.fila - tile.fila) + Mathf.Abs(target.columna - tile.columna);
                    tile.f = tile.g + tile.h;
                    abiertos.Add(tile);
                }
            }

        }

        //actualTargetTile = currentTile;
        //moverHaciaCasilla(actualTargetTile);
        return;
    }

    public void encontrarCaminoSeleccionado(Tile target)
    {
        GameObject[] generateGrid = GameObject.FindGameObjectsWithTag("GenerateGrid");
        List<Tile> abiertos = new List<Tile>();
        GetCurrentTile();

        currentTile.parent = null;
        currentTile.padres = new Stack<Tile>();
        currentTile.h = Mathf.Abs(target.fila - currentTile.fila) + Mathf.Abs(target.columna - currentTile.columna);
        currentTile.f = currentTile.h;
        abiertos.Add(currentTile);

        List<Tile> cerrados = new List<Tile>();

        while (abiertos.Count > 0)
        {

            Tile q = FindLowestF(abiertos);

            q.FindNeighbors(0, q);

            cerrados.Add(q);

            foreach (Tile tile in q.vecinos)
            {

                if (tile == target)
                {
                    //actualTargetTile = FindEndTile(tile);
                    //actualTargetTile = encontrarCasillaFinal(tile);
                    moverHaciaCasillaAlt(target);
                    return;
                }

                if (tile.walkable)
                {
                    if (abiertos.Contains(tile))
                    {
                        float tempG = q.g + 1;

                        if (tempG < tile.g)
                        {
                            tile.parent = q;
                            //tile.padres.Clear();
                            tile.padres = new Stack<Tile>(new Stack<Tile>(q.padres));
                            //Debug.Log("ANTES: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);
                            tile.padres.Push(q);
                            //Debug.Log("DESPS: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);

                            tile.g = tempG;
                            tile.f = tile.g + tile.h;
                        }
                    }
                    else if (cerrados.Contains(tile))
                    {
                        // NADA
                    }
                    else
                    {
                        tile.parent = q;
                        //tile.padres.Clear();
                        tile.padres = new Stack<Tile>(new Stack<Tile>(q.padres));
                        //Debug.Log("ANTES: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);
                        tile.padres.Push(q);
                        //Debug.Log("DESPS: " + tile.showStack(tile.padres) + " (" + tile.fila + ", " + tile.columna + ")" + "|| COUNT: " + tile.padres.Count);

                        tile.g = q.g + 1;
                        tile.h = Mathf.Abs(target.fila - tile.fila) + Mathf.Abs(target.columna - tile.columna);
                        tile.f = tile.g + tile.h;
                        abiertos.Add(tile);
                    }
                }
            }

        }

        //actualTargetTile = currentTile;
        //moverHaciaCasillaAlt(actualTargetTile);
        return;
    }

    //**********************

    protected void Init()
    {
        tiles = GameObject.FindGameObjectsWithTag("Tile");
        //casillas = GameObject.FindGameObjectsWithTag("Tile");

        halfHeight = GetComponent<Collider>().bounds.extents.y;

        TurnManager.AddUnit(this);
    }

    public void GetCurrentTile()
    {
        currentTile = GetTargetTile(gameObject);
        currentTile.current = true;
    }

    public Tile GetTargetTile(GameObject target)
    {
        RaycastHit hit;
        Tile tile = null;

        if (Physics.Raycast(target.transform.position, -Vector3.up, out hit, 1))
        {
            tile = hit.collider.GetComponent<Tile>();
        }

        return tile;
    }

    public void ComputeAdjacencyLists(float jumpHeight, Tile target)
    {
        //tiles = GameObject.FindGameObjectsWithTag("Tile");

        foreach (GameObject tile in tiles)
        {
            Tile t = tile.GetComponent<Tile>();
            t.FindNeighbors(jumpHeight, target);
        }

    }

    public void FindSelectableTiles()
    {
        ComputeAdjacencyLists(jumpHeight, null);
        GetCurrentTile();

        Queue<Tile> process = new Queue<Tile>();

        process.Enqueue(currentTile);
        currentTile.visited = true;
        //currentTile.parent = ??  leave as null 

        while (process.Count > 0)
        {
            Tile t = process.Dequeue();

            selectableTiles.Add(t);
            t.selectable = true;

            if (t.distance < move)
            {
                foreach (Tile tile in t.adjacencyList)
                {
                    if (!tile.visited)
                    {
                        tile.parent = t;
                        tile.visited = true;
                        tile.distance = 1 + t.distance;
                        process.Enqueue(tile);
                    }
                }
            }
        }
    }

    public void MoveToTile(Tile tile)
    {
        path.Clear();
        tile.target = true;
        moving = true;

        Tile next = tile;
        while (next != null)
        {
            Debug.Log("TILE (" + next.fila + ", " + next.columna + ")");
            path.Push(next);
            next = next.parent;
        }
    }

    public void moverHaciaCasilla(Tile tile)
    {
        path.Clear();
        //tile.parent.target = true;
        //tile.target = true;
        //tile.walkable = false;
        tile.padres.Peek().target = true;
        tile.padres.Peek().walkable = false;
        moving = true;

        while (tile.padres.Count > 0)
        {
            if(tile.padres.Count == 1 && path.Count > 0)
            {
                tile.padres.Peek().walkable = true;
            }
            //Debug.Log("TILE (" + tile.padres.Peek().fila + ", " + tile.padres.Peek().columna + ")");
            path.Push(tile.padres.Peek());
            tile.padres.Pop();
        }

        Debug.Log("PATH: " + path.Count);
        
    }

    public void moverHaciaCasillaAlt(Tile tile)
    {
        path.Clear();
        tile.target = true;
        tile.walkable = false;
        moving = true;
        tile.padres.Push(tile);

        while (tile.padres.Count > 0)
        {
            if (tile.padres.Count == 1 && path.Count > 0)
            {
                tile.padres.Peek().walkable = true;
            }
            //Debug.Log("TILE (" + tile.padres.Peek().fila + ", " + tile.padres.Peek().columna + ")");
            path.Push(tile.padres.Peek());
            tile.padres.Pop();
        }
    }

    public void Move()
    {
        if (path.Count > 0)
        {
            Tile t = path.Peek();
            Vector3 target = t.transform.position;

            //Calculate the unit's position on top of the target tile
            target.y += halfHeight + t.GetComponent<Collider>().bounds.extents.y;

            if (Vector3.Distance(transform.position, target) >= 0.05f)
            {
                bool jump = transform.position.y != target.y;

                if (jump)
                {
                    Jump(target);
                }
                else
                {
                    CalculateHeading(target);
                    SetHorizotalVelocity();
                }

                //Locomotion
                transform.forward = heading;
                transform.position += velocity * Time.deltaTime;
            }
            else
            {
                //Tile center reached
                transform.position = target;
                path.Pop();
            }
        }
        else
        {
            RemoveSelectableTiles();
            moving = false;
            TurnManager.EndTurn();
        }
    }

    protected void RemoveSelectableTiles()
    {
        if (currentTile != null)
        {
            currentTile.current = false;
            currentTile = null;
        }

        foreach (Tile tile in selectableTiles)
        {
            tile.Reset();
        }

        foreach (GameObject tile in casillas)
        {
            Tile t = tile.GetComponent<Tile>();
            t.Reset();
        }

        selectableTiles.Clear();
    }

    void CalculateHeading(Vector3 target)
    {
        heading = target - transform.position;
        heading.Normalize();
    }

    void SetHorizotalVelocity()
    {
        velocity = heading * moveSpeed;
    }

    void Jump(Vector3 target)
    {
        if (fallingDown)
        {
            FallDownward(target);
        }
        else if (jumpingUp)
        {
            JumpUpward(target);
        }
        else if (movingEdge)
        {
            MoveToEdge();
        }
        else
        {
            PrepareJump(target);
        }
    }

    void PrepareJump(Vector3 target)
    {
        float targetY = target.y;
        target.y = transform.position.y;

        CalculateHeading(target);

        if (transform.position.y > targetY)
        {
            fallingDown = false;
            jumpingUp = false;
            movingEdge = true;

            jumpTarget = transform.position + (target - transform.position) / 2.0f;
        }
        else
        {
            fallingDown = false;
            jumpingUp = true;
            movingEdge = false;

            velocity = heading * moveSpeed / 3.0f;

            float difference = targetY - transform.position.y;

            velocity.y = jumpVelocity * (0.5f + difference / 2.0f);
        }
    }

    void FallDownward(Vector3 target)
    {
        velocity += Physics.gravity * Time.deltaTime;

        if (transform.position.y <= target.y)
        {
            fallingDown = false;
            jumpingUp = false;
            movingEdge = false;

            Vector3 p = transform.position;
            p.y = target.y;
            transform.position = p;

            velocity = new Vector3();
        }
    }

    void JumpUpward(Vector3 target)
    {
        velocity += Physics.gravity * Time.deltaTime;

        if (transform.position.y > target.y)
        {
            jumpingUp = false;
            fallingDown = true;
        }
    }

    void MoveToEdge()
    {
        if (Vector3.Distance(transform.position, jumpTarget) >= 0.05f)
        {
            SetHorizotalVelocity();
        }
        else
        {
            movingEdge = false;
            fallingDown = true;

            velocity /= 5.0f;
            velocity.y = 1.5f;
        }
    }
    
    protected Tile FindLowestF(List<Tile> list)
    {
        Tile lowest = list[0];

        foreach (Tile t in list)
        {
            if (t.f < lowest.f)
            {
                lowest = t;
            }
        }

        list.Remove(lowest);

        return lowest;
    }

    protected Tile FindEndTile(Tile t)
    {
        Stack<Tile> tempPath = new Stack<Tile>();

        Tile next = t.parent;
        while (next != null)
        {
            Debug.Log("PUSH " + next.fila + ", " + next.columna + ": " + next.f);
            tempPath.Push(next);
            next = next.parent;
        }

        Debug.Log("COSTE: " + tempPath.Count + " || MOV: " + move);
        if (tempPath.Count <= move)
        {
            return t.parent;
        }

        Tile endTile = null;
        for (int i = 0; i <= move; i++)
        {
            endTile = tempPath.Pop();
        }

        return endTile;
    }

    public Tile encontrarCasillaFinal(Tile t)
    {
        Stack<Tile> tempPath = new Stack<Tile>(new Stack<Tile>(t.padres));
        tempPath.Push(t);
        //Debug.Log("(" + tempPath.Peek().fila + ", " + tempPath.Peek().columna + ") || COSTE: " + tempPath.Count + " || MOV: " + move);

        while (tempPath.Count > move)
        {
            tempPath.Pop();
            //Debug.Log("(" + tempPath.Peek().fila + ", " + tempPath.Peek().columna + ") || COSTE: " + tempPath.Count + " || MOV: " + move);
        }

        Debug.Log("CASILLA FINAL = (" + tempPath.Peek().fila + ", " + tempPath.Peek().columna + ") || COSTE: " + tempPath.Count + " || MOV: " + move);
        return tempPath.Peek();
    }

    /*protected void FindPath(Tile target)
    {
        //ComputeAdjacencyLists(jumpHeight, target);
        GetCurrentTile();

        List<Tile> openList = new List<Tile>();
        List<Tile> closedList = new List<Tile>();

        openList.Add(currentTile);
        currentTile.parent = null;
        currentTile.h = Vector3.Distance(currentTile.transform.position, target.transform.position);
        currentTile.f = currentTile.h;

        Debug.Log("Current Tile " + currentTile.fila + ", " + currentTile.columna);
        while (openList.Count > 0)
        {
            Tile q = FindLowestF(openList);
            Debug.Log("Tile with lowest F " + q.fila + ", " + q.columna);
            if(q.vecinos.Count <= 0)
            {
                Debug.Log("La lista de adyacencia está vacía");
            }

            closedList.Add(q);
            if (closedList.Count <= 0)
            {
                Debug.Log("La lista de cerrados está vacía");
            }

            if (q == target)
            {
                //actualTargetTile = FindEndTile(q);
                actualTargetTile = encontrarCasillaFinal(q);
                Debug.Log("Actual Target Tile " + actualTargetTile.fila + ", " + actualTargetTile.columna);
                MoveToTile(actualTargetTile);
                return;
            }

            foreach (Tile tile in q.vecinos)  
            {
                if (closedList.Contains(tile))
                {
                    //Do nothing, already processed
                }
                else if (openList.Contains(tile))
                {
                    float tempG = q.g + Vector3.Distance(tile.transform.position, q.transform.position);

                    if (tempG < tile.g)
                    {
                        tile.parent = q;

                        tile.g = tempG;
                        tile.f = tile.g + tile.h;
                    }
                }
                else
                {
                    tile.parent = q;

                    tile.g = q.g + Vector3.Distance(tile.transform.position, q.transform.position);
                    tile.h = Vector3.Distance(tile.transform.position, target.transform.position);
                    tile.f = tile.g + tile.h;

                    openList.Add(tile);
                }
            }
        }

        //todo - what do you do if there is no path to the target tile?
        return;
        
    }*/

    public void BeginTurn()
    {
        turn = true;
    }

    public void EndTurn()
    {
        turn = false;
    }

}
