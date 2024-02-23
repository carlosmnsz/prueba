using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : TacticsMove 
{

    // Use this for initialization
    void Start () 
	{
        Init();
	}
	
	// Update is called once per frame
	void Update () 
	{
        Debug.DrawRay(transform.position, transform.forward);

        if (!turn)
        {
            
            if(TurnManager.turnoJugador && Input.GetMouseButtonUp(0))
            {
                //Debug.Log("¿CONTAINS?: " + TurnManager.currentGroup.Contains(this));
                Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

                RaycastHit hit;
                if (Physics.Raycast(ray, out hit))
                {
                    if (hit.collider.tag == "Player")
                    {
                        PlayerMove p = hit.collider.GetComponent<PlayerMove>();
                        if (TurnManager.currentGroup.Contains(p))
                        {
                            p.BeginTurn();
                        }
                    }
                }
            }
            return;
        }

        if (!moving)
        {
            //FindSelectableTiles();
            encontrarCasillasSeleccionables();
            CheckMouse();
            encontrarCasillasSeleccionables();
            if (Input.GetMouseButtonUp(1))
            {
                Debug.Log("ATRÁS");
                RemoveSelectableTiles();
                turn = false;
            }
        }
        else
        {
            Move();
        }
	}

    void CheckMouse()
    {
        if (Input.GetMouseButtonUp(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

            RaycastHit hit;
            if (Physics.Raycast(ray, out hit))
            {
                if (hit.collider.tag == "Tile")
                {
                    Tile t = hit.collider.GetComponent<Tile>();

                    if (t.selectable)
                    {
                        //MoveToTile(t);
                        encontrarCaminoSeleccionado(t);
                    }
                }
            }
        }
    }
}
