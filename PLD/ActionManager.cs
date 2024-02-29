using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ActionManager : MonoBehaviour
{

    static TacticsMove actual;
    static bool wait = false;

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

    public static bool EndOfAction()
    {
        if (wait)
        {
            TurnManager.EndTurn(actual);
            wait = false;
            actual = null;
            return true;
        }

        return false;
    }
}
