using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateGrid : MonoBehaviour
{
    public int rows = 9; // Número de filas
    public int columns = 9; // Número de columnas
    public float cubeSize = 1f; // Tamaño de cada cubo
    public Texture2D textura; // La textura que quieres asignar al cubo

    public GameObject[,] grid;

    void Start()
    {
        grid = new GameObject[rows, columns];
        GenerateCubeMatrix();
    }

    void GenerateCubeMatrix()
    {
        
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < columns; col++)
            {
                // Calcula la posición del cubo
                Vector3 position = new Vector3(col * cubeSize, 0f, row * cubeSize);

                // Crea un nuevo cubo en la posición calculada
                GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
                cube.transform.position = position;
                if(row == 0 && col == 0)
                {
                    cube.transform.position = new Vector3(0f, 2f, 0f);
                }
                cube.transform.localScale = new Vector3(cubeSize, cubeSize, cubeSize);

                
                // Obtenemos el componente Renderer del cubo
                Renderer rend = cube.GetComponent<Renderer>();

                // Cargamos la textura "Madera.png" desde los recursos del proyecto
                textura = Resources.Load<Texture2D>("CasillaNormal");

                if (textura == null)
                {
                    Debug.LogError("No se pudo cargar la textura 'CasillaNormal.png'");
                    return;
                }

                // Creamos un nuevo material y asignamos la textura a este material
                Material material = new Material(Shader.Find("Standard")); // Selecciona el shader adecuado
                material.mainTexture = textura;

                // Asignamos el material al cubo
                rend.material = material;

                cube.AddComponent<Tile>();
                cube.tag = "Tile";
                cube.GetComponent<Tile>().fila = row;
                cube.GetComponent<Tile>().columna = col;

                grid[row, col] = cube;
            }
        }
    }
}
