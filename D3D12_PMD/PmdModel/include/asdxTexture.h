﻿//-------------------------------------------------------------------------------------------------
// File : asdxTexture.h
// Desc : Texture Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once


//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxRef.h>
#include <d3d12.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// Texture class
///////////////////////////////////////////////////////////////////////////////////////////////////
class Texture
{
public:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Desc structure
    ///////////////////////////////////////////////////////////////////////////////////////////////
    struct Desc
    {
        D3D12_RESOURCE_DESC         ResourceDesc;
        D3D12_CPU_DESCRIPTOR_HANDLE HandleCPU;
        bool                        IsCubeMap;

        //-----------------------------------------------------------------------------------------
        //! @brief      コンストラクタです
        //-----------------------------------------------------------------------------------------
        Desc();
    };

    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    Texture();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    ~Texture();

    //---------------------------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice     デバイスです.
    //! @param[in]      desc        構成設定です.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //---------------------------------------------------------------------------------------------
    bool Init( ID3D12Device* pDevice, Desc& desc );
       
    //---------------------------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //---------------------------------------------------------------------------------------------
    void Term();

    //---------------------------------------------------------------------------------------------
    //! @brief      サブリソースを更新します.
    //!
    //! @param[in]      pCmdList    コマンドリストです.
    //! @param[in]      pData       サブリソースです.
    //! @retval true    アップロードに成功.
    //! @retval true    更新処理に成功.
    //! @retval false   更新処理に失敗.
    //---------------------------------------------------------------------------------------------
    bool Upload(
        ID3D12GraphicsCommandList*  pCmdList,
        D3D12_SUBRESOURCE_DATA*     pData,
        ID3D12Resource**            ppIntermediate );

    //---------------------------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //---------------------------------------------------------------------------------------------
    ID3D12Resource* operator -> () const;

    //---------------------------------------------------------------------------------------------
    //! @brief      リソースを取得します.
    //!
    //! @return     リソースを返却します.
    //---------------------------------------------------------------------------------------------
    ID3D12Resource* GetResource() const;

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12Resource>  m_Resource;
    D3D12_RESOURCE_STATES   m_State;

    //=============================================================================================
    // private methods.
    //=============================================================================================
    /* NOTHING */
};


} // namespace asdx
