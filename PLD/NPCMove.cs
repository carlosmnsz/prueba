﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NPCMove : TacticsMove 
{
    GameObject target;

	// Use this for initialization
	void Start () 
	{
        Init();
	}
	
	// Update is called once per frame
	protected virtual void Update () 
	{
        Debug.DrawRay(transform.position, transform.forward);

        if (!turn)
        {
            return;
        }

        if (!moving)
        {
            FindNearestTarget();
            CalculatePath();
            //FindSelectableTiles();
            encontrarCasillasSeleccionables();
            //actualTargetTile.target = true;
        }
        else
        {
            Move();
        }
	}

    void CalculatePath()
    {
        Tile targetTile = GetTargetTile(target);
        //FindPath(targetTile);
        encontrarCamino(targetTile);
        //Debug.Log("Target Tile " + targetTile.fila + ", " + targetTile.columna);
    }

    void FindNearestTarget()
    {
        GameObject[] targets = GameObject.FindGameObjectsWithTag("Player");

        GameObject nearest = null;
        float distance = Mathf.Infinity;

        foreach (GameObject obj in targets)
        {
            float d = Vector3.Distance(transform.position, obj.transform.position);

            if (d < distance)
            {
                distance = d;
                nearest = obj;
            }
        }

        target = nearest;
    }
}
